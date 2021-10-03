/**
 * @file hash.h
 * @author Ivan Fedorov <inbox@titaniumhocker.ru>
 * @copyright MIT Licence
 * @date 2021
 * @brief File containing implementation of some hash functions.
 * 
 * @see https://en.wikipedia.org/wiki/Hash_function
 * 
 */

#ifndef __LIBBICYCLES_HASH_H__
#define __LIBBICYCLES_HASH_H__

#define BICYCLES_DJB2_MAGIC_HASH 5381 ///< Magic start hash for djb2 hash function

/**
 * @brief djb2 hash function
 * 
 * Written by Daniel J. Bernstein (also known as djb),
 * this simple hash function dates back to 1991.
 * 
 * This hash function is similar to a Linear Congruential Generator.
 * LCG - a simple class of functions that generate a series of psuedo-random numbers.
 * 
 * @see <https://theartincode.stanis.me/008-djb2/>
 * @see <https://en.wikipedia.org/wiki/Linear_congruential_generator>.
 * 
 * @param string String for hashing.
 * @returns Result number of srting hashing.
 */
unsigned long djb2(char* string);

#endif /* __LIBBICYCLES_HASH_H__ */
