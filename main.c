// extern 사용 금지  & 표준 입출력은 여기에서만  & 더 이상의 include 불가  

// 입출력을 통해 환자 정보 구조체 생성 및 linked list 저장 코드 구현 : ifct_database.h 활용  
// 특정 조건에 맞는 환자의 정보 출력 코드 구현 -> 01, 02, 03 
// 환자의 전파자를 추적하고 최초 전파자를 알아내는 코드 구현  -> 04 

// 역할 : 프로그램의 주요 동작 프름 실현  

#include <stdio.h>
#include <string.h>
#include "ifct_element.h"
#include "ifct_database.h"

#define MENU_PATIENT        1
#define MENU_PLACE          2 
#define MENU_AGE            3
#define MENU_TRACK          4
#define MENU_EXIT           0

#define TIME_HIDE           2


int trackInfester(int patient_no, int *detected_time, int *place);

int main(int argc, const char * argv[]) {
    
    int menu_selection;
    void *ifct_element;
    FILE* fp;
    int index, age, detected_time;
    int history_place[N_HISTORY]; 
    void *obj;
    int num;
    int place_char;
    int min_age, max_age;
    
    //------------- 1. loading patient info file ------------------------------
    //1-1. FILE pointer open
    /*if (argc != 2)
    {
        printf("[ERROR] syntax : infestPath (file path).");
        return -1;
    }
    
    fp = fopen(argv[1],"r");
    if (fp == NULL)
    {
        printf("[ERROR] Failed to open database file!! (%s)\n", argv[1]);
        return -1;
    } */
    
    //1-2. loading each patient informations
    
    //2022 10_문자열 입출력 실습  
    
    fp=fopen("patientInfo_sample.txt","r"); // 파일 읽기  
    //ifctele_genElement(index, age, detected_time, history_place[N_HISTORY]); -> 이거 있으면 실행 X 

    // 2, 환자 정보 전체 저장

   /* while((fscanf(fp,"%d" "%d" "%d",&pIndex, &age, &time)) == 3) { // 입력받은 값이 3개가 존재하는지를 확인 + 3개의 변수에 값 저장  
    	
    	int i;
    
    	printf("%d번째 환자 감염 경로 : ",pIndex);
    	
    	for(i=0;i<5;i++) {   
    		fscanf(fp,"%d",&placeHist[i]); // placeHist[]에 3-7번째 숫자(이동경로) 대입 : fscanf의 경우, 앞에서 사용했으면 그 뒤의 값부터 저장함  
    		printf("%s   ",ifctele_getPlaceName(placeHist[i])); // 숫자(이동경로)를 나라로 반환  
		}
		
		ifct_element=ifctele_genElement(index,age, ...);
		ifctdb_addtail(ifct_element); 
		
		ifctele_genElement(ifct_element); // 이거랑 바로 아래는 진짜 프로젝트 실현할 때는 지워야 함  
		age=ifctele_genAge(ifct_element);
		
    	printf("\n");
	} */
    

    //1-3. FILE pointer close
    fclose(fp);  
    
    do {
        printf("\n=============== INFECTION PATH MANAGEMENT PROGRAM (No. of patients : %i) =============\n", ifctdb_len());
        printf("1. Print details about a patient.\n");                      //MENU_PATIENT
        printf("2. Print list of patients infected at a place.\n");        //MENU_PLACE
        printf("3. Print list of patients in a range of age.\n");          //MENU_AGE
        printf("4. Track the root of the infection\n");                     //MENU_TRACK
        printf("0. Exit.\n");                                               //MENU_EXIT
        printf("=============== ------------------------------------------------------- =============\n\n");
        
        printf("Select a menu :");
        scanf("%d", &menu_selection);
        fflush(stdin);
        
        switch(menu_selection)
        {
            case MENU_EXIT:
                printf("Exiting the program... Bye bye.\n");
                break;
                
            case MENU_PATIENT: {
            	
            	printf("번호 입력 : ");
            	scanf("%i",&num);
            	obj=&num;
				ifctele_printElement(obj); } 
				 
				break;
                
            /*case MENU_PLACE: { // 특정 장소에서 감염이 확인된 환자 정보 출력  
            	printf("장소 입력 : ");
            	scanf("%d",&place_char); 
            	// ...

			}
                
                break;
                
            case MENU_AGE: { // 특정 나이에 해당하는 환자 정보 출력  
            	printf("최소 나이 입력 : ");
            	scanf("%i",&min_age);
            	printf("최대 나이 입력 : ");
            	scanf("%i",&max_age);
            	
            	for(i=0;i<N_HISTORY;i++) { // 해당 범위에 해당하는 나이를 가진 환자의 정보만 출력  
            		
            		if((age>min_age) && (age<max_age))
            			ifctele_printElement(obj);
				}

			}
                
                break; */
                
            case MENU_TRACK: // 감염경로 및 최초 전파자 추척  
                    
                break;
                
            default:
                printf("[ERROR Wrong menu selection! (%i), please choose between 0 ~ 4\n", menu_selection);
                break;
        }
    
    } while(menu_selection != 0);
    
    
    return 0;
}
