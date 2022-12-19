//
//  ifct_database.h
//  infection Path
//
//  Created by Juyeop Kim on 2022/10/20.
//

#ifndef ifct_database_h
#define ifct_database_h


int ifctdb_addTail(void* obj);          //add data to tail
int ifctdb_deleteData(int index);       //delete data (데이터 삭제) 
int ifctdb_len(void);                   //get database length (데이터베이스 길이) : 데이터가 몇 개 있는지 출력 
void* ifctdb_getData(int index);        //get index'th data : 몇 번째인지 넣으면 데이터를 출력  

#endif /* ifct_database_h */
