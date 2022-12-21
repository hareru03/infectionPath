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
    int input_num;
    //int place_char;
    //int min_age, max_age;
    
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
    
    fp=fopen("patientInfo_sample.txt","r"); // 파일 읽기  

   while((fscanf(fp,"%d" "%d" "%d",&index, &age, &detected_time)) == 3) { 
   
    	int i;
    	
    	for(i=0;i<5;i++) {   
    		fscanf(fp,"%d",&history_place[i]); 
			//printf("%s   ",ifctele_getPlaceName(history_place[i]));
			//history_place[i] = ifctele_getPlaceName(history_place[i]); // 숫자(이동경로)를 나라로 반환  
		}
		
		ifct_element=ifctele_genElement(index,age,detected_time,history_place); // 구조체 생성  
		ifctdb_addTail(ifct_element); // 구조체 저장  

		
		//ifctele_genElement(ifct_element); // 이거랑 바로 아래는 진짜 프로젝트 실현할 때는 지워야 함  
		//age=ifctele_genAge(ifct_element);

	}
	
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
            	scanf("%d",input_num);

            	//ifctele_printElement(ifctdb_getData(input_num));} // 여기에서 값도 안 나오고 프로그램이 끝나버림  
            	
				ifctele_printElement(ifct_element); } 
				 
				break;
                
            case MENU_PLACE: //{ 
            	/*printf("장소 입력 : ");
            	scanf("%d",&place_char); 
            	
            	사용자가 입력한 장소에서 감염이 확인된 환자 정보 출력  

			} */
                
                break;
                
            case MENU_AGE: //{ 
            	/*printf("최소 나이 입력 : ");
            	scanf("%i",&min_age);
            	printf("최대 나이 입력 : ");
            	scanf("%i",&max_age);
            	
            	for(i=0;i<N_HISTORY;i++) {   
            		
            		if((age>min_age) && (age<max_age))
						해당 범위에 해당하는 나이를 가진 환자 정보 출력  
				}

			} */
                
                break;
                
            case MENU_TRACK: // 감염경로 및 최초 전파자 추척  
                    
                break;
                
            default:
                printf("[ERROR Wrong menu selection! (%i), please choose between 0 ~ 4\n", menu_selection);
                break;
        }
    
    } while(menu_selection != 0);
    
    
    return 0;
}
