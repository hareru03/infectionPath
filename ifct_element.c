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
/*typedf struct ifs_ele{

	int index; //number
	int age; //age
	int infested_time; //time
	place_t place[N_HISROTY];//place[N_HISTORY]

}ifs_ele_t; 



void* ifctele_genElement(int index, int age, unsigned int detected_time, int history_place[N_HISTORY]) {
	
	ifs_ele_t* ptr;
	malloc(); 
	ptr=malloc();
	
	ptr->index=index; 
	ptr->age=age;
	// ...
	
	// 여기에는 free(ptr);를 넣으면 안 됨 : 언젠가는 free를 사용해야 한다는 말일 뿐 여기서는 사용하면 X  
	return ptr;
	
}

int ifctele_getAge(void* obj) { // 환자의 일부정보만 알고 싶을 때 ex) 나이.. 
	
	ifs_ele_t* ptr=(ifs_ele_t*)obj;
	return ptr->age*;// 나이를 알고 싶기 떄문 
	
}
// ifctele_getHistPlaceIndex랑  ifctele_getinfestedTime도 return ptr->()* 이런 식으로 작성  

int ifctele_getHistPlaceIndex(void* obj, int index) {
	
	ifs_ele_t* ptr=(ifs_ele_t*)obj;
	return ptr->place_t place[N_HISROTY]*; // 이거는 비슷하지만 어떻게 다른 방식으로 해야 한다고 했는데..;; 
}

unsigned int ifctele_getinfestedTime(void* obj) {
	
	ifs_ele_t* ptr=(ifs_ele_t*)obj;
	return ptr->infested_time*; // 이것도 내가 작성한건데 맞는 지 모름  
}

void ifctele_printElement(void* obj) {
	
	ifs_ele_t* ptr=(ifs_ele_t*)obj;
	printf("age : %i\n",ptr->age); // 아직 안 끝남  
	
}
*/
