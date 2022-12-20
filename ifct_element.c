// 환자 정보 구조체 생성 및 구조체 내부 변수를 접근할 수 있는 함수 구현
// 환자 정보를 출력하는 함수 구현 
// 역할 : 감염자 정보 구조체를 다루며, 구조체 instance 생성과 내용 분석 역할 

// 구조체 ifct_ele_t의 정의가 이뤄지며 여기서만 사용  

//  ifs_element.c
//  InfestPath
//
//  Created by Juyeop Kim on 2020/10/20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ifct_element.h"

typedef enum place {
    Seoul,          //0
    Jeju,           //1
    Tokyo,          //2
    LosAngeles,     //3
    NewYork,        //4
    Texas,          //5
    Toronto,        //6
    Paris,          //7
    Nice,           //8
    Rome,           //9
    Milan,          //10
    London,         //11
    Manchester,     //12
    Basel,          //13
    Luzern,         //14
    Munich,         //15
    Frankfurt,      //16
    Berlin,         //17
    Barcelona,      //18
    Madrid,         //19
    Amsterdam,      //20
    Stockholm,      //21
    Oslo,           //22
    Hanoi,          //23
    Bangkok,        //24
    KualaLumpur,    //25
    Singapore,      //26
    Sydney,         //27
    SaoPaulo,       //28
    Cairo,          //29
    Beijing,        //30
    Nairobi,        //31
    Cancun,         //32
    BuenosAires,    //33
    Reykjavik,      //34
    Glasgow,        //35
    Warsow,         //36
    Istanbul,       //37
    Dubai,          //38
    CapeTown        //39
} place_t;

char countryName[N_PLACE+1][MAX_PLACENAME] =
{   "Seoul",
    "Jeju",
    "Tokyo",
    "LosAngeles",
    "NewYork",
    "Texas",
    "Toronto",
    "Paris",
    "Nice",
    "Rome",
    "Milan",
    "London",
    "Manchester",
    "Basel",
    "Luzern",
    "Munich",
    "Frankfurt",
    "Berlin",
    "Barcelona",
    "Madrid",
    "Amsterdam",
    "Stockholm",
    "Oslo",
    "Hanoi",
    "Bangkok",
    "KualaLumpur",
    "Singapore",
    "Sydney",
    "SaoPaulo",
    "Cairo",
    "Beijing",
    "Nairobi",
    "Cancun",
    "BuenosAires",
    "Reykjavik",
    "Glasgow",
    "Warsow",
    "Istanbul",
    "Dubai",
    "CapeTown",
    "Unrecognized"
};

// 숫자를 나라 이름으로 변환하여 출력하는 함수 
char* ifctele_getPlaceName(int placeIndex) {
	return countryName[placeIndex];
}

//with 교수님 : 구조체 틀  
typedef struct ifs_ele{

	int index; //number
	int age; //age
	int time; //time
	place_t place[N_HISTORY]; //place[N_HISTORY]

}ifs_ele_t; 



void* ifctele_genElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY]) {
	
	ifs_ele_t* ptr;
	
	int i;

	ptr= (int*)malloc(100*sizeof(int));
	
	ptr->index = index; 
	ptr->age = age;
	ptr->time = detected_time;
	
	for(i=0;i<N_HISTORY;i++) {
		
		ptr->place[i] = history_place[N_HISTORY];
	}
	
	// 여기에는 free(ptr);를 넣으면 안 됨 : 언젠가는 free를 사용해야 한다는 말일 뿐 여기서는 사용하면 X  
	return ptr;
	
}

// 환자의 나이를 출력  
int ifctele_getAge(void* obj) { 
	
	ifs_ele_t* ptr=(ifs_ele_t*)obj;
	return ptr->age;
	
}
// ifctele_getHistPlaceIndex랑  ifctele_getinfestedTime도 return ptr->()* 이런 식으로 작성  

// 환자의 이동경로 출력 -> 여기선 일단 이것만 오류  
/*int ifctele_getHistPlaceIndex(void* obj, int index) {
	
	ifs_ele_t* ptr=(ifs_ele_t*)obj;
	
	int i;
	for(i=0;i<N_HISTORY;i++) {
		
		ptr->place[i] = history_place[N_HISTORY] ;
	}
	
	return ptr;
} */

unsigned int ifctele_getinfestedTime(void* obj) {
	
	ifs_ele_t* ptr=(ifs_ele_t*)obj;
	return ptr->time;
}

void ifctele_printElement(void* obj) {
	
	ifs_ele_t* ptr=(ifs_ele_t*)obj;
	printf("age : %i\n",ptr->age); // 아직 안 끝남  
	
}
