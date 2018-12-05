/*############################################################################
  # Copyright 2018 BITMAINTECH PTE LTD.
  #
  # Licensed under the Apache License, Version 2.0 (the "License");
  # you may not use this file except in compliance with the License.
  # You may obtain a copy of the License at
  #
  #     http://www.apache.org/licenses/LICENSE-2.0
  #
  # Unless required by applicable law or agreed to in writing, software
  # distributed under the License is distributed on an "AS IS" BASIS,
  # WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  # See the License for the specific language governing permissions and
  # limitations under the License.
############################################################################*/
/*!
 * \file
 * load prebuilt files, ONLY for test.
*/

/* system header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* epdia common header files */
#include "include/epida_define.h"
#include "util/buffutil.h"
#include "include/epida_define.h"


#define CREDENTIAL_FILE_NAME       "epid_credential.dat"
#define NONCE_FILE_NAME            "epid_nonce.dat"
#define TRANSACTION_FILE_NAME      "transaction.dat"


INT32 load_cacert(const CHAR* res_directory_path)
{
    CHAR cacert_file_path[EPIDA_FILE_PATH_MAX] = { 0 };

    snprintf(cacert_file_path, sizeof(cacert_file_path) - 1, "%s%s%s",
             res_directory_path,
             PATH_SLASH,
             CACERT_FILE_NAME);

    CHAR  cacert_data[] = {
            0x02, 0x00, 0x00, 0x11, 0xE3, 0xF5, 0x5A, 0xBF, 0xF9, 0xE1, 0x8E, 0xAD, 0xC0, 0x38, 0xC0, 0xAB,
            0x28, 0xA4, 0x80, 0x2A, 0x09, 0x0D, 0x4D, 0xBE, 0x0C, 0x4F, 0x31, 0x92, 0x15, 0x1F, 0x2C, 0x9D,
            0xB7, 0x12, 0x91, 0xC4, 0xE2, 0xE9, 0xAC, 0x1D, 0x52, 0x29, 0x29, 0xDE, 0xE1, 0x1D, 0xFF, 0x40,
            0xE2, 0xFC, 0x1A, 0x87, 0x0B, 0x17, 0xCF, 0x9C, 0xB7, 0x7E, 0x95, 0x9C, 0xD6, 0x8B, 0x23, 0x93,
            0xFE, 0xE1, 0x0C, 0xD6, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
            0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
            0xFF, 0xFF, 0xFF, 0xFC, 0x5A, 0xC6, 0x35, 0xD8, 0xAA, 0x3A, 0x93, 0xE7, 0xB3, 0xEB, 0xBD, 0x55,
            0x76, 0x98, 0x86, 0xBC, 0x65, 0x1D, 0x06, 0xB0, 0xCC, 0x53, 0xB0, 0xF6, 0x3B, 0xCE, 0x3C, 0x3E,
            0x27, 0xD2, 0x60, 0x4B, 0x6B, 0x17, 0xD1, 0xF2, 0xE1, 0x2C, 0x42, 0x47, 0xF8, 0xBC, 0xE6, 0xE5,
            0x63, 0xA4, 0x40, 0xF2, 0x77, 0x03, 0x7D, 0x81, 0x2D, 0xEB, 0x33, 0xA0, 0xF4, 0xA1, 0x39, 0x45,
            0xD8, 0x98, 0xC2, 0x96, 0x4F, 0xE3, 0x42, 0xE2, 0xFE, 0x1A, 0x7F, 0x9B, 0x8E, 0xE7, 0xEB, 0x4A,
            0x7C, 0x0F, 0x9E, 0x16, 0x2B, 0xCE, 0x33, 0x57, 0x6B, 0x31, 0x5E, 0xCE, 0xCB, 0xB6, 0x40, 0x68,
            0x37, 0xBF, 0x51, 0xF5, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
            0xFF, 0xFF, 0xFF, 0xFF, 0xBC, 0xE6, 0xFA, 0xAD, 0xA7, 0x17, 0x9E, 0x84, 0xF3, 0xB9, 0xCA, 0xC2,
            0xFC, 0x63, 0x25, 0x51, 0x5F, 0x96, 0xDC, 0xA2, 0x64, 0x58, 0x85, 0x67, 0x02, 0xBE, 0x71, 0x37,
            0x4D, 0xE6, 0x80, 0x64, 0xAC, 0x57, 0x9B, 0xAC, 0x24, 0x85, 0x48, 0x62, 0xBC, 0x38, 0x1A, 0xEC,
            0x8E, 0x44, 0x02, 0xC3, 0xC1, 0xD6, 0x26, 0xBA, 0x1B, 0xB2, 0xBC, 0x23, 0xD4, 0xFB, 0x4A, 0x4C,
            0x20, 0x71, 0x13, 0x5E, 0xCD, 0x04, 0x1B, 0x6D, 0x8A, 0xDD, 0x35, 0xC7, 0x70, 0xEA, 0xA3, 0x37,
            0x5A, 0x24, 0x45, 0xD8
    };

    if (0 != WriteLoud(cacert_data, sizeof(cacert_data), cacert_file_path))
    {
        return EPIDA_WRITE_FILE_FAIL;
    }

    return EPIDA_OK;
}

INT32 load_pubkey(const CHAR* res_directory_path)
{
    CHAR pubkey_file_path[EPIDA_FILE_PATH_MAX] = { 0 };

    snprintf(pubkey_file_path, sizeof(pubkey_file_path) - 1, "%s%s%s",
             res_directory_path,
             PATH_SLASH,
             PUBKEY_FILE_NAME);

    CHAR pubkey_data[] = {
            0x02, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x45, 0xCB, 0x06, 0x04, 0xB3, 0xF7, 0x23, 0xB2, 0xD1, 0xD1, 0x0D, 0x4F,
            0x51, 0x7B, 0xBB, 0x8F, 0x71, 0x15, 0xD7, 0xF1, 0xDC, 0x15, 0x37, 0xC8, 0xB8, 0x3D, 0x68, 0x0A,
            0x18, 0xA5, 0x34, 0x14, 0x0C, 0xDC, 0xD9, 0x15, 0x7E, 0xBA, 0x56, 0xC5, 0xE5, 0x61, 0xFA, 0x6A,
            0x86, 0xA0, 0xAC, 0x6A, 0x81, 0x36, 0x6D, 0x01, 0x5F, 0x86, 0xC0, 0x04, 0x8B, 0x1E, 0xFF, 0x49,
            0xD9, 0x37, 0x96, 0x66, 0xF1, 0xC3, 0x16, 0xB5, 0xC5, 0x1C, 0x67, 0xB6, 0xFF, 0x28, 0x23, 0x79,
            0x59, 0xEA, 0x80, 0xE6, 0x09, 0x07, 0xE7, 0xD3, 0x38, 0xEC, 0xB9, 0x16, 0x83, 0x88, 0xDA, 0x64,
            0xDD, 0xC4, 0x9D, 0x6A, 0x5C, 0xB2, 0x1C, 0x88, 0x97, 0xEA, 0xAF, 0xA9, 0xF3, 0x3E, 0x07, 0xEA,
            0xB6, 0x2A, 0xD5, 0x7A, 0xED, 0x32, 0xD9, 0x3D, 0x90, 0xD7, 0xB9, 0x91, 0x08, 0x05, 0x9E, 0xE3,
            0x22, 0x75, 0x06, 0x35, 0xE5, 0xC4, 0x77, 0xAD, 0x52, 0xB9, 0x7C, 0x04, 0x2D, 0x7E, 0x81, 0xF2,
            0x5D, 0x5D, 0x52, 0x7D, 0xD7, 0x1D, 0x29, 0xFB, 0x6A, 0xA7, 0xBC, 0xB5, 0xA9, 0x1A, 0xA6, 0xFD,
            0x20, 0xEA, 0xF2, 0x98, 0xE2, 0x67, 0x33, 0x28, 0x67, 0x5F, 0xBE, 0x23, 0xA0, 0x43, 0xE8, 0x71,
            0xAA, 0xAB, 0xF6, 0xF0, 0x6A, 0x2B, 0x52, 0xA8, 0x61, 0x51, 0x22, 0x44, 0x00, 0x91, 0xD7, 0xF1,
            0x7E, 0x05, 0x48, 0xDC, 0x51, 0x0C, 0xEF, 0xA0, 0xF3, 0x72, 0xCD, 0x59, 0xD4, 0x7A, 0x2A, 0x60,
            0xA3, 0x62, 0x54, 0xA8, 0xB6, 0x8F, 0xED, 0x90, 0xDF, 0x3E, 0x94, 0xE8, 0xA4, 0x89, 0x32, 0xAA,
            0x52, 0x5A, 0x97, 0xAE, 0x4C, 0x86, 0xF4, 0xBA, 0xEC, 0xC6, 0x36, 0x13, 0x87, 0x42, 0x5D, 0x16,
            0x49, 0x12, 0x66, 0xC5, 0xE0, 0xE4, 0x9B, 0xF9, 0x68, 0xAA, 0xA9, 0x95, 0x81, 0x16, 0x5C, 0xD2,
            0xCA, 0xD4, 0x2E, 0x61, 0x49, 0x2F, 0xBC, 0x95, 0xAD, 0xF2, 0x74, 0xDB, 0x4A, 0x48, 0xA1, 0x88,
            0xDB, 0xB1, 0x9D, 0x31, 0x9C, 0xD6, 0xC3, 0x93, 0x93, 0xFC, 0x55, 0xBD, 0x54, 0xA6, 0x93, 0xC4,
            0x49, 0xE1, 0xEE, 0xC3, 0xA4, 0x72, 0x43, 0x54, 0xD0, 0xD4, 0xE7, 0xD9, 0x09, 0x01, 0xCD, 0x3E,
            0xBF, 0xA5, 0x69, 0xC0, 0x16, 0x21, 0x5B, 0xC2, 0xEA, 0x5F, 0x21, 0xE2, 0xD8, 0x2B, 0x7F, 0xDD,
            0xAD, 0x02, 0x6D, 0xCE
    };

    if (0 != WriteLoud(pubkey_data, sizeof(pubkey_data), pubkey_file_path))
    {
        return EPIDA_WRITE_FILE_FAIL;
    }

    return EPIDA_OK;
}


INT32 load_credential(const CHAR* res_directory_path)
{
    CHAR credential_file_path[EPIDA_FILE_PATH_MAX] = { 0 };

    snprintf(credential_file_path, sizeof(credential_file_path) - 1, "%s%s%s",
             res_directory_path,
             PATH_SLASH,
             CREDENTIAL_FILE_NAME);

    CHAR credential_data[] = {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0xCA, 0x24, 0x49, 0x67, 0x86, 0x98, 0xFE, 0x05, 0xD2, 0x66, 0xC5, 0x7C, 0xD2, 0x40, 0xB6, 0xED,
            0x4F, 0x76, 0xC0, 0xB8, 0x08, 0x62, 0x9A, 0x56, 0x46, 0x76, 0x01, 0x40, 0xD8, 0xA3, 0xE1, 0xB8,
            0x2F, 0x83, 0x64, 0x88, 0x99, 0xCA, 0xD3, 0x2B, 0xD9, 0x50, 0xFB, 0x74, 0x8B, 0xA5, 0x32, 0xB8,
            0xCE, 0x31, 0xD7, 0x56, 0x4B, 0xDD, 0xDD, 0x1C, 0x0E, 0x5E, 0xBA, 0x34, 0x68, 0x66, 0xBC, 0xB6,
            0x9C, 0x92, 0xF0, 0x2F, 0xA2, 0x27, 0x56, 0xC1, 0xEF, 0x3A, 0x21, 0x5E, 0x9A, 0x05, 0x13, 0x63,
            0x0E, 0x2F, 0x12, 0xAC, 0x95, 0xB9, 0x26, 0x6D, 0x1D, 0xE2, 0xCF, 0x64, 0x4A, 0x09, 0xDD, 0x4F
    };

    if (0 != WriteLoud(credential_data, sizeof(credential_data), credential_file_path))
    {
        return EPIDA_WRITE_FILE_FAIL;
    }

    return EPIDA_OK;
}

INT32 load_nonce(const CHAR* res_directory_path)
{
    CHAR nonce_file_path[EPIDA_FILE_PATH_MAX] = { 0 };

    snprintf(nonce_file_path, sizeof(nonce_file_path) - 1, "%s%s%s",
             res_directory_path,
             PATH_SLASH,
             NONCE_FILE_NAME);

    CHAR nonce_data[] = {
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
            0x0a, 0x0b, 0x0c, 0x0d, 0x0f, 0x00, 0x01, 0x02
    };

    if (0 != WriteLoud(nonce_data, sizeof(nonce_data), nonce_file_path))
    {
        return EPIDA_WRITE_FILE_FAIL;
    }

    return EPIDA_OK;
}

static INT32 load_privatef(const CHAR* res_directory_path)
{
    CHAR privatef_file_path[EPIDA_FILE_PATH_MAX] = { 0 };

    snprintf(privatef_file_path, sizeof(privatef_file_path) - 1, "%s%s%s",
             res_directory_path,
             PATH_SLASH,
             PRIVATEF_FILE_NAME);


    CHAR privatf_data[] = {
            0x15, 0x9D, 0x08, 0x6B, 0x93, 0xBF, 0x95, 0x89, 0x11, 0xB8, 0x31, 0x11, 0xB1, 0x36, 0x76, 0x4D,
            0x0A, 0xBE, 0x5A, 0x42, 0xE7, 0x44, 0xBB, 0x17, 0x6D, 0x36, 0x7B, 0x80, 0x0B, 0x10, 0x1E, 0xC6
    };

    if (0 != WriteLoud(privatf_data, sizeof(privatf_data), privatef_file_path))
    {
        return EPIDA_WRITE_FILE_FAIL;
    }

    return EPIDA_OK;
}

INT32 load_mprivkey(const CHAR* res_directory_path)
{
    CHAR mprivkey_file_path[EPIDA_FILE_PATH_MAX] = { 0 };

    snprintf(mprivkey_file_path, sizeof(mprivkey_file_path) - 1, "%s%s%s",
             res_directory_path,
             PATH_SLASH,
             MPRIVKEY_FILE_NAME);


    CHAR mprivkey_data[] = {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0xCA, 0x24, 0x49, 0x67, 0x86, 0x98, 0xFE, 0x05, 0xD2, 0x66, 0xC5, 0x7C, 0xD2, 0x40, 0xB6, 0xED,
            0x4F, 0x76, 0xC0, 0xB8, 0x08, 0x62, 0x9A, 0x56, 0x46, 0x76, 0x01, 0x40, 0xD8, 0xA3, 0xE1, 0xB8,
            0x2F, 0x83, 0x64, 0x88, 0x99, 0xCA, 0xD3, 0x2B, 0xD9, 0x50, 0xFB, 0x74, 0x8B, 0xA5, 0x32, 0xB8,
            0xCE, 0x31, 0xD7, 0x56, 0x4B, 0xDD, 0xDD, 0x1C, 0x0E, 0x5E, 0xBA, 0x34, 0x68, 0x66, 0xBC, 0xB6,
            0x9C, 0x92, 0xF0, 0x2F, 0xA2, 0x27, 0x56, 0xC1, 0xEF, 0x3A, 0x21, 0x5E, 0x9A, 0x05, 0x13, 0x63,
            0x0E, 0x2F, 0x12, 0xAC, 0x95, 0xB9, 0x26, 0x6D, 0x1D, 0xE2, 0xCF, 0x64, 0x4A, 0x09, 0xDD, 0x4F,
            0x15, 0x9D, 0x08, 0x6B, 0x93, 0xBF, 0x95, 0x89, 0x11, 0xB8, 0x31, 0x11, 0xB1, 0x36, 0x76, 0x4D,
            0x0A, 0xBE, 0x5A, 0x42, 0xE7, 0x44, 0xBB, 0x17, 0x6D, 0x36, 0x7B, 0x80, 0x0B, 0x10, 0x1E, 0xC6
    };

    if (0 != WriteLoud(mprivkey_data, sizeof(mprivkey_data), mprivkey_file_path))
    {
        return EPIDA_WRITE_FILE_FAIL;
    }

    return EPIDA_OK;
}

INT32 load_bsnlist(const CHAR* res_directory_path)
{
    CHAR basename_list_file_path[EPIDA_FILE_PATH_MAX] = { 0 };

    snprintf(basename_list_file_path, sizeof(basename_list_file_path) - 1, "%s%s%s",
             res_directory_path,
             PATH_SLASH,
             BASENAME_LIST_FILE_NAME);

    CHAR basenames_data[] = {
            0x7B, 0x0A, 0x0D, 0x0A, 0x20, 0x20, 0x22, 0x62, 0x61, 0x73, 0x65, 0x6E, 0x61, 0x6D, 0x65, 0x43,
            0x6F, 0x75, 0x6E, 0x74, 0x22, 0x3A, 0x20, 0x22, 0x31, 0x30, 0x22, 0x2C, 0x0D, 0x0A, 0x20, 0x20,
            0x0A, 0x22, 0x62, 0x61, 0x73, 0x65, 0x6E, 0x61, 0x6D, 0x65, 0x73, 0x22, 0x3A, 0x0A, 0x5B, 0x0A,
            0x7B, 0x22, 0x62, 0x61, 0x73, 0x65, 0x6E, 0x61, 0x6D, 0x65, 0x22, 0x3A, 0x22, 0x30, 0x22, 0x7D,
            0x2C, 0x7B, 0x22, 0x62, 0x61, 0x73, 0x65, 0x6E, 0x61, 0x6D, 0x65, 0x22, 0x3A, 0x22, 0x31, 0x22,
            0x7D, 0x2C, 0x7B, 0x22, 0x62, 0x61, 0x73, 0x65, 0x6E, 0x61, 0x6D, 0x65, 0x22, 0x3A, 0x22, 0x32,
            0x22, 0x7D, 0x2C, 0x7B, 0x22, 0x62, 0x61, 0x73, 0x65, 0x6E, 0x61, 0x6D, 0x65, 0x22, 0x3A, 0x22,
            0x33, 0x22, 0x7D, 0x2C, 0x7B, 0x22, 0x62, 0x61, 0x73, 0x65, 0x6E, 0x61, 0x6D, 0x65, 0x22, 0x3A,
            0x22, 0x34, 0x22, 0x7D, 0x2C, 0x7B, 0x22, 0x62, 0x61, 0x73, 0x65, 0x6E, 0x61, 0x6D, 0x65, 0x22,
            0x3A, 0x22, 0x35, 0x22, 0x7D, 0x2C, 0x7B, 0x22, 0x62, 0x61, 0x73, 0x65, 0x6E, 0x61, 0x6D, 0x65,
            0x22, 0x3A, 0x22, 0x36, 0x22, 0x7D, 0x2C, 0x7B, 0x22, 0x62, 0x61, 0x73, 0x65, 0x6E, 0x61, 0x6D,
            0x65, 0x22, 0x3A, 0x22, 0x37, 0x22, 0x7D, 0x2C, 0x7B, 0x22, 0x62, 0x61, 0x73, 0x65, 0x6E, 0x61,
            0x6D, 0x65, 0x22, 0x3A, 0x22, 0x38, 0x22, 0x7D, 0x2C, 0x7B, 0x22, 0x62, 0x61, 0x73, 0x65, 0x6E,
            0x61, 0x6D, 0x65, 0x22, 0x3A, 0x22, 0x39, 0x22, 0x7D, 0x0A, 0x5D, 0x0D, 0x0A, 0x0D, 0x7D
    };

    if (0 != WriteLoud(basenames_data, sizeof(basenames_data), basename_list_file_path))
    {
        return EPIDA_WRITE_FILE_FAIL;
    }

    return EPIDA_OK;
}

INT32 load_transaction(const CHAR* res_directory_path)
{
    CHAR transaction_file_path[EPIDA_FILE_PATH_MAX] = { 0 };

    snprintf(transaction_file_path, sizeof(transaction_file_path) - 1, "%s%s%s",
             res_directory_path,
             PATH_SLASH,
             TRANSACTION_FILE_NAME);

    char transaction_data[] = {0x0a, 0x0b, 0x0c,0x0d, 0x0e, 0x0f};
    if (0 != WriteLoud(transaction_data, sizeof(transaction_data), transaction_file_path))
    {
        return EPIDA_WRITE_FILE_FAIL;
    }

    return EPIDA_OK;
}

/* ONLY test interface to provide the test data about epid key meterial files */
INT32 load_epid_prebuilt_files(const CHAR* res_directory_path)
{
    INT32 ret = EPIDA_OK;

    if (NULL == res_directory_path)
    {
        return EPIDA_NO_RES_PATH;
    }

    UINT32 res_directory_path_len = (UINT32)strlen(res_directory_path);
    if ((0 == res_directory_path_len) || (res_directory_path_len > EPIDA_RES_DIR_PATH_MAX))
    {
        return EPIDA_INVALID_RES_PATH_LEN;
    }

    do
    {
        if (EPIDA_OK != load_cacert(res_directory_path))
        {
            ret = EPIDA_WRITE_FILE_FAIL;
            break;
        }

        if (EPIDA_OK != load_pubkey(res_directory_path))
        {
            ret = EPIDA_WRITE_FILE_FAIL;
            break;
        }

        if (EPIDA_OK != load_bsnlist(res_directory_path))
        {
            ret = EPIDA_WRITE_FILE_FAIL;
            break;
        }

        if (EPIDA_OK != load_credential(res_directory_path))
        {
            ret = EPIDA_WRITE_FILE_FAIL;
            break;
        }

        if (EPIDA_OK != load_nonce(res_directory_path))
        {
            ret = EPIDA_WRITE_FILE_FAIL;
            break;
        }

        if (EPIDA_OK != load_privatef(res_directory_path))
        {
            ret = EPIDA_WRITE_FILE_FAIL;
            break;
        }

        if (EPIDA_OK != load_mprivkey(res_directory_path))
        {
            ret = EPIDA_WRITE_FILE_FAIL;
            break;
        }

        if (EPIDA_OK != load_transaction(res_directory_path))
        {
            ret = EPIDA_WRITE_FILE_FAIL;
            break;
        }
    }while(0);

    return EPIDA_OK;
}
