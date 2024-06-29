/*
 This file is part of the Yildiz-Engine project, licenced under the MIT License  (MIT)
 Copyright (c) 2024 Grégory Van den Borre
 More infos available: https://engine.yildiz-games.be
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 documentation files (the "Software"), to deal in the Software without restriction, including without limitation
 the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright
 notice and this permission notice shall be included in all copies or substantial portions of the  Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
 OR COPYRIGHT  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include "library.h"
#include <bitarchivewriter.hpp>
#include <bitarchivereader.hpp>
#include <bitfilecompressor.hpp>

LIB_EXPORT int decompress(const char* lib7zipPath, const char* archiveFile, const char* outputDirectory) {

    try {
        bit7z::Bit7zLibrary nativeLib { lib7zipPath };
        bit7z::BitArchiveReader archive{ nativeLib, archiveFile, bit7z::BitFormat::SevenZip };
        archive.extractTo(outputDirectory);
        return 0;
    } catch ( const bit7z::BitException& ex ) {
        return ex.posixCode();
    }
}

LIB_EXPORT int compressSingleFile(const char* lib7zipPath, const char* fileToCompress, const char* outputFile) {
    try {
        bit7z::Bit7zLibrary nativeLib { lib7zipPath };
        bit7z::BitArchiveWriter archive{ nativeLib, bit7z::BitFormat::SevenZip };
        archive.addFile(fileToCompress);
        archive.setCompressionLevel(bit7z::BitCompressionLevel::Ultra);
        archive.compressTo(outputFile);
        return 0;
    } catch ( const bit7z::BitException& ex ) {
        return ex.posixCode();
    }
}

LIB_EXPORT int compressMultipleFiles(const char* lib7zipPath, const char** filesToCompress, int numberOfFiles, const char* outputFile) {
    try {
        bit7z::Bit7zLibrary nativeLib { lib7zipPath };
        bit7z::BitFileCompressor compressor{ nativeLib, bit7z::BitFormat::SevenZip };
        std::vector<std::string> files;
        for(int i = 0; i < numberOfFiles; i++) {
            files.push_back(filesToCompress[i]);
        }
        compressor.setSolidMode(true);
        compressor.setCompressionLevel(bit7z::BitCompressionLevel::Ultra);
        compressor.compressFiles(files, outputFile);
        return 0;
    } catch ( const bit7z::BitException& ex ) {
        return ex.posixCode();
    }
}
