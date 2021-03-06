/*****************************************************************************
 *   discoSnp++: discovering polymorphism from raw unassembled NGS reads
 *   A tool from the GATB (Genome Assembly Tool Box)
 *   Copyright (C) 2020  INRIA
 *   Authors: P.Peterlongo, E.Drezen
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

/*
 * read_mapper.h
 *
 *  Created on: 15 sept. 2010
 *      Author: ppeterlo
 */

#ifndef EXTENSION_ALGORITHM_H_
#define EXTENSION_ALGORITHM_H_

#include <fragment.h>
#include <fragment_index.h>
#include <stdio.h>
#include <commons.h>
#include <string.h>
#include <stdlib.h>
#include <interface_xhash.h>
#include <limits.h>
#include <gatb/gatb_core.hpp>


class ReadMapper{
public:
    IBank* inputBank;
    
    int read_set_id;
    size_t  nbCores;
    ReadMapper(IBank* inputBank, int read_set_id, size_t  nbCores){
        this->inputBank=inputBank;
        this->read_set_id=read_set_id;
        this->nbCores=nbCores;
    };

    u_int64_t map_all_reads_from_a_file (
                                         GlobalValues & gv,
                                         FragmentIndex & index,
                                         const int read_set_id
                                );
    

    
    void set_read_coherency(GlobalValues& gv, FragmentIndex index);

};


#endif /* EXTENSION_ALGORITHM_H_ */
