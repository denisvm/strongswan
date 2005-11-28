/**
 * @file receiver.h
 *
 * @brief Interface of receiver_t.
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

#ifndef RECEIVER_H_
#define RECEIVER_H_

#include <types.h>

typedef struct receiver_t receiver_t;

/**
 * @brief Receives packets from the socket and adds them to the job queue.
 * 
 * The receiver starts a thread, wich reads on the blocking socket. If 
 * there is data available, a packet_t is created from the data, wrapped
 * in an incoming_packet_job_t and added to the job queue.
 * 
 * @ingroup threads
 */
struct receiver_t {

	/**
	 * @brief Destroys a receiver_t
	 *
	 * @param receiver 	receiver object
	 */
	void (*destroy) (receiver_t *receiver);
};

/**
 * @brief Create a receiver.
 * 
 * The receiver thread will start working, get data
 * from the socket and add those packets to the job queue.
 * 
 * @return
 * 					- created receiver_t, or
 * 					- NULL of thread could not be started
 * 
 * @ingroup threads
 */
receiver_t * receiver_create();

#endif /*RECEIVER_H_*/
