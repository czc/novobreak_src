/*
 * 
 * Copyright (c) 2013, Zechen Chong <chongzechen@gmail.com>
 *
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FILTER_KMER_H
#define FILTER_KMER_H

#include <stdint.h>
#include <unistd.h>
#include "timer.h"
#include "file_reader.h"
#include "hashset.h"
#include "string.h"
#include "list.h"
#include "dna.h"
#include "sort.h"
#include "bitvec.h"

#define UNIQ_KMER_MAX_KSIZE 31
#define UNIQ_KMER_MAX_CNT 3071

typedef struct {
	uint64_t kmer, cnt:12;
} kmer_t;

#define kmer_hashcode(k) u64hashcode((k).kmer)
#define kmer_equals(k1, k2) ((k1).kmer == (k2).kmer)
define_hashset(kmerhash, kmer_t, kmer_hashcode, kmer_equals);

#ifdef __CPLUSPLUS
extern "C" {
#endif

kmerhash* build_kmerhash(FileReader *fr, uint32_t ksize, int is_fq);
uint64_t filter_ctrl_kmers(kmerhash *hash, FileReader *fr, uint32_t ksize, int is_fq);
uint64_t filter_ref_kmers(kmerhash *hash, FileReader *fr, uint32_t ksize);

#ifdef __CPLUSPLUS
}
#endif

#endif
