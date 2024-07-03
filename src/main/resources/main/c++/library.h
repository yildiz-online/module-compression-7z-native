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
#ifndef COMMON_COMPRESSION_7Z_LIBRARY_H
#define COMMON_COMPRESSION_7Z_LIBRARY_H

#ifdef _WIN32
#define LIB_EXPORT __declspec(dllexport)
#elif __linux__
#define LIB_EXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

    LIB_EXPORT int decompress7z(const char* lib7zipPath, const char* archiveFile, const char* outputDirectory);

    LIB_EXPORT int decompressZip(const char* lib7zipPath, const char* archiveFile, const char* outputDirectory);

    LIB_EXPORT int compressSingleFile7z(const char* lib7zipPath, const char* fileToCompress, const char* outputFile);

    LIB_EXPORT int compressSingleFileZip(const char* lib7zipPath, const char* fileToCompress, const char* outputFile);

    LIB_EXPORT int compressMultipleFiles7z(const char* lib7zipPath, const char** filesToCompress, int numberOfFiles, const char* outputFile);

    LIB_EXPORT int compressMultipleFilesZip(const char* lib7zipPath, const char** filesToCompress, int numberOfFiles, const char* outputFile);


#ifdef __cplusplus
}
#endif
#endif
