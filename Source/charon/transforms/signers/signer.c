/**
 * @file signer.c
 * 
 * @brief Implementation of generic signer_t constructor.
 * 
 */

/*
 * Copyright (C) 2005 Jan Hutter, Martin Willi
 * Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#include "signer.h"

#include <transforms/signers/hmac_signer.h>

/** 
 * string mappings for integrity_algorithm_t
 */
mapping_t integrity_algorithm_m[] = {
	{AUTH_UNDEFINED, "AUTH_UNDEFINED"},
	{AUTH_HMAC_MD5_96, "AUTH_HMAC_MD5_96"},
	{AUTH_HMAC_SHA1_96, "AUTH_HMAC_SHA1_96"},
	{AUTH_DES_MAC, "AUTH_DES_MAC"},
	{AUTH_KPDK_MD5, "AUTH_KPDK_MD5"},
	{AUTH_AES_XCBC_96, "AUTH_AES_XCBC_96"},
	{MAPPING_END, NULL}
};


/*
 * see header
 */
signer_t *signer_create(integrity_algorithm_t integrity_algorithm)
{
	switch(integrity_algorithm)
	{
		case AUTH_HMAC_SHA1_96:
		{
			return ((signer_t *) hmac_signer_create(HASH_SHA1));
		}
		case AUTH_HMAC_MD5_96:
		{
			return ((signer_t *) hmac_signer_create(HASH_MD5));
		}
		default:
			return NULL;
	}
}
