#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <time.h>
struct vaccinerecord
{
    char name[50];
    char given[3][30];
    char pending[3][30];
    char parent[50];
    char bloodgroup[20];
    char contact[20];
    int count;
};
struct AppointmentSlot
{
    char day[10];
    char date[15];
    char time[20];
    int booked;   
};
FILE *fp;
int main()
{  
    time_t t;
    struct tm *tm_info;
    char currentDate[15];
    char currentDay[10];

    time(&t);
    tm_info = localtime(&t);

    strftime(currentDate, sizeof(currentDate), "%d-%m-%Y", tm_info);
    strftime(currentDay, sizeof(currentDay), "%A", tm_info);
    struct AppointmentSlot vaccinationSlots[10] =
    {
        { "", "", "10:00 AM", 0 },
        { "", "", "10:45 AM", 0 },
        { "", "", "11:15 AM", 0 },
        { "", "", "12:30 PM", 0 },
        { "", "", "01:00 PM", 0 },
        { "", "", "02:15 PM", 0 },
        { "", "", "03:30 PM", 0 },
        { "", "", "04:45 PM", 0 },
        { "", "", "06:00 PM", 0 },
        { "", "", "07:15 PM", 0 }
    };
    struct AppointmentSlot routineSlots[10] =
    {
        { "", "", "09:00 AM", 0 },
        { "", "", "10:00 AM", 0 },
        { "", "", "11:00 AM", 0 },
        { "", "", "12:00 PM", 0 },
        { "", "", "01:00 PM", 0 },
        { "", "", "02:00 PM", 0 },
        { "", "", "03:00 PM", 0 },
        { "", "", "04:00 PM", 0 },
        { "", "", "05:00 PM", 0 },
        { "", "", "06:00 PM", 0 }
    };
    struct AppointmentSlot labSlots[5] =
    {
        { "", "", "09:30 AM", 0 },
        { "", "", "10:30 AM", 0 },
        { "", "", "11:30 AM", 0 },
        { "", "", "12:30 PM", 0 },
        { "", "", "01:30 PM", 0 }
    };
    struct AppointmentSlot dentalSlots[10] =
    {
        { "", "", "10:00 AM", 0 },
        { "", "", "10:45 AM", 0 },
        { "", "", "11:15 AM", 0 },
        { "", "", "12:30 PM", 0 },
        { "", "", "01:00 PM", 0 },
        { "", "", "02:15 PM", 0 },
        { "", "", "03:30 PM", 0 },
        { "", "", "04:45 PM", 0 },
        { "", "", "06:00 PM", 0 },
        { "", "", "07:15 PM", 0 }
    };
    for(int i=0;i<10;i++)
    {
        strcpy(vaccinationSlots[i].day, currentDay);
        strcpy(vaccinationSlots[i].date, currentDate);

        strcpy(routineSlots[i].day, currentDay);
        strcpy(routineSlots[i].date, currentDate);

        strcpy(dentalSlots[i].day, currentDay);
        strcpy(dentalSlots[i].date, currentDate);
    }
    for(int i=0;i<5;i++)
    {
        strcpy(labSlots[i].day, currentDay);
        strcpy(labSlots[i].date, currentDate);
    }
    struct vaccinerecord records[100];
    int recordindex=0;
    char name[50];
    char parent[50]; 
    char bloodgroup[20];
    char contact[20];
    int age,choice,slot,menuchoice,injury,dental,lab,labchoice,test,appointmentchoice, service, delSlot;
    char gievn[3][30];
    char pending[3][30];
    int count=0;
    int num;
    printf("\n========================================================================");
    printf("\n               PEDIATRIC CLINIC MANAGEMENT SYSTEM           ");
    printf("\n========================================================================");
    printf("\n1.Vaccination");
    printf("\n2.Routine Check up");
    printf("\n3.First-Aid");
    printf("\n4.Laboratory services");
    printf("\n5.Dental Care");
    printf("\n6.Delete Appointment");
    printf("\n7.Exit");
    do
    {
    printf("\nEnter your choice=");
    scanf("%d",&menuchoice);
    printf("\n----------------------------------------------------");
    switch(menuchoice)
    {
          case 1:
                  printf("\n\nEnter baby's name : ");
                  scanf("%s",&records[recordindex].name);
                  printf("\nEnter Blood group of baby :");
                  scanf("%s",&records[recordindex].bloodgroup);
                  printf("\nEnter Parent name : ");
                  scanf("%s",records[recordindex].parent);
                  printf("\nEnter Parent contact number : ");
                  scanf("%s",&records[recordindex].contact);
                  printf("--------------------------------------------------");
                  printf("\n\nSelect age group : ");
                  printf("\n1. 0 to 3 months");
                  printf("\n2. 4 to 6 months");
                  printf("\n3. 7 to 12 months");
                  printf("\n4. 2 years");
                  printf("\n5. 3 to 5 years");
                  printf("\n6. 6 to 8 years");
                  printf("\n7. 9 to 12 years");
                  printf("\n\nEnter option number=");
                  scanf("%d",&age);
                  records[recordindex].count=0;
                  switch(age)
                  {
                    case 1:strcpy(records[recordindex].given[0],"BCG");
                           strcpy(records[recordindex].given[1],"OPV-0");
                           strcpy(records[recordindex].pending[0],"Hepatitis B");
                           strcpy(records[recordindex].pending[1],"OPV");
                           records[recordindex].count=2;
                           break;
                    case 2:strcpy(records[recordindex].given[0],"Pentavalent-1");
                           strcpy(records[recordindex].given[1],"OPV-1");
                           strcpy(records[recordindex].pending[0],"Rotavirus");
                            strcpy(records[recordindex].pending[1],"DTap");
                           records[recordindex].count=2;
                           break;
                    case 3:strcpy(records[recordindex].given[0],"Pentavalent-2");
                           strcpy(records[recordindex].given[1],"OPV-2");
                           strcpy(records[recordindex].pending[0],"Measles");
                            strcpy(records[recordindex].pending[1],"IPV");
                           records[recordindex].count=2;
                           break;
                    case 4:strcpy(records[recordindex].given[0],"MMR");
                           strcpy(records[recordindex].pending[0],"Booster Dose");
                           records[recordindex].count=1;
                           break;
                    case 5:strcpy(records[recordindex].given[0],"Booster Dose");
                           strcpy(records[recordindex].pending[0],"Tetanus");
                           records[recordindex].count=1;
                           break;
                    case 6:strcpy(records[recordindex].given[0],"Tetanus");
                           strcpy(records[recordindex].pending[0],"Varicella");
                           records[recordindex].count=1;
                           break;
                    case 7:strcpy(records[recordindex].given[0],"All completed");
                           strcpy(records[recordindex].pending[0],"None");
                           records[recordindex].count=1;
                           break;
                    default: printf("\nInvalid Option");
                  }
                  printf("\n=========================================================");
                  printf("\nVaccine details for - %s\n",records[recordindex].name);
                  printf("\n=========================================================");
                  printf("\n----------------------------------------------------\n");
                  printf("SR no\tGiven Vaccines\t\tPending Vaccines\n");
                  printf("-----------------------------------------------------\n");
                  for(int i=0;i<records[recordindex].count;i++)
                  {
                    printf("%d\t%-20s\t%s\n",i+1,records[recordindex].given[i],records[recordindex].pending[i]);

                  }
                  
                  printf("\n\nEnter 1 to book appointment and Enter 0 to book appointment later\n");
                  scanf("%d",&choice);
                  printf("\n=========================================================");
                  if(choice==1)
                  {
                     printf("\nAvailable Time Slots for vaccination");
                     printf("\n=========================================================");
                     for(int i=0;i<10;i++)
                     {
                            if(vaccinationSlots[i].booked == 0)
                            {
                                printf("\n%d. %s | %s | %s\n",
                                          i+1,
                                        vaccinationSlots[i].day,
                                        vaccinationSlots[i].date,
                                        vaccinationSlots[i].time);
                             }
                     }
                     printf("\n\nEnter Slot Option Number = ");
                     scanf("%d",&slot);
                     vaccinationSlots[slot - 1].booked = 1;
                     printf("\n=========================================================");
                     printf("\nYOUR APPOINTMENT IS BOOKED");
                     printf("\nREPORT TO THE CLINIC 15 mins PRIOR TO SELECTED SLOT");
                     printf("\nThank you");
                     printf("\n=========================================================");
                  }
                  else
                  {
                      printf("\nThank you");
                  } 
                  fp = fopen("clinic.txt", "a");   
                  fprintf(fp, "-------------------------------\n");
                  fprintf(fp, "Baby Name     : %s\n", records[recordindex].name);
                  fprintf(fp, "Blood Group   : %s\n", records[recordindex].bloodgroup);
                  fprintf(fp, "Parent Name   : %s\n", records[recordindex].parent);
                  fprintf(fp, "Contact No    : %s\n", records[recordindex].contact);
                  fprintf(fp, "Service Used  : %d\n", menuchoice);
                  if (choice==1)
                  {
                    fprintf(fp, "Appointment Slot   : %d\n", slot);
                    fprintf(fp, "Appointment Status : BOOKED\n");
                    fprintf(fp, "Appointment Day    : %s\n", vaccinationSlots[slot-1].day);
                    fprintf(fp, "Appointment Date   : %s\n", vaccinationSlots[slot-1].date);
                    fprintf(fp, "Appointment Time   : %s\n", vaccinationSlots[slot-1].time);
                  }
                  else
                  {
                     fprintf(fp, "Appointment Status : NOT BOOKED\n");
                  }
                  for (int i = 0; i < records[recordindex].count; i++)
                     {
                        fprintf(fp, "Given    : %s\n", records[recordindex].given[i]);
                        fprintf(fp, "Pending  : %s\n", records[recordindex].pending[i]);
                     }
                  fprintf(fp, "--------------------------------\n\n");
                  fclose(fp);
                  recordindex++;
                  break;
          case 2:printf("\n==========================================================");
                   printf("\n\nEnter baby's name : ");
                  scanf("%s",&records[recordindex].name);
                  printf("\nEnter Blood group of baby :");
                  scanf("%s",&records[recordindex].bloodgroup);
                  printf("\nEnter Parent name : ");
                  scanf("%s",records[recordindex].parent);
                  printf("\nEnter Parent contact number : ");
                  scanf("%s",&records[recordindex].contact);
                  printf("\nEnter 1 to book appointment and enter 0 to book appointment later\n");
                  scanf("%d",&choice);
                  if(choice==1)
                  {
                     printf("\n==========================================================");
                     printf("\nAvailable Time Slots routine check up");
                     printf("\n=========================================================");
                     for(int i=0;i<10;i++)
                     {
                         if(routineSlots[i].booked == 0)
                         {
                              printf("\n%d. %s | %s | %s\n",
                                 i+1,
                                 routineSlots[i].day,
                                 routineSlots[i].date,
                                 routineSlots[i].time);
                         }
                     }
                     printf("\n\nEnter Slot Option Number = ");
                     scanf("%d",&slot);
                     routineSlots[slot - 1].booked = 1;
                     printf("\n=========================================================");
                     printf("\nYOUR APPOINTMENT IS BOOKED");
                     printf("\nREPORT TO THE CLINIC 15 mins PRIOR TO SELECTED SLOT");
                      printf("\n=========================================================");
                  }
                  else
                  {  
                      printf("\n=========================================================");
                     printf("\nThank you");
                     printf("\n=========================================================");
                  }
                     fp = fopen("clinic.txt", "a");   
                  fprintf(fp, "-------------------------------\n");
                  fprintf(fp, "Baby Name     : %s\n", records[recordindex].name);
                  fprintf(fp, "Blood Group   : %s\n", records[recordindex].bloodgroup);
                  fprintf(fp, "Parent Name   : %s\n", records[recordindex].parent);
                  fprintf(fp, "Contact No    : %s\n", records[recordindex].contact);
                  fprintf(fp, "Service Used  : %d\n", menuchoice);
                  if (choice==1)
                  {
                    fprintf(fp, "Appointment Status : BOOKED\n");
                    fprintf(fp, "Appointment Slot   : %d\n", slot);
                    fprintf(fp, "Appointment Day    : %s\n", routineSlots[slot-1].day);
                    fprintf(fp, "Appointment Date   : %s\n", routineSlots[slot-1].date);
                    fprintf(fp, "Appointment Time   : %s\n", routineSlots[slot-1].time);
                  }
                  else
                  {
                     fprintf(fp, "Appointment Status : NOT BOOKED\n");
                  }
                  fprintf(fp, "-------------------------------\n\n");
                  fclose(fp);
                     recordindex++;
                     break;
          case 3:printf("\n==========================================================");
                  printf("\n\nEnter baby's name : ");
                  scanf("%s",&records[recordindex].name);
                  printf("\nEnter Blood group of baby :");
                  scanf("%s",&records[recordindex].bloodgroup);
                  printf("\nEnter Parent name : ");
                  scanf("%s",records[recordindex].parent);
                  printf("\nEnter Parent contact number : ");
                  scanf("%s",&records[recordindex].contact);
                  printf("\n==========================================================");
                  printf("\n                    INJURY                              ");
                     printf("\n=========================================================");
                     printf("\n1. Fracture");
                     printf("\n2.scrape and bruises");
                     printf("\n3.sprain");
                     printf("\n4.cut and bleeding");
                     printf("\n5.Burns");
                     printf("\n\nEnter Type of injury : ");
                     scanf("%d",&injury);
                     printf("\n-------------------------------------------------------");
                     printf("\nREPORT TO THE CLINIC AS FAST AS POSSIBLE");
                     printf("\n--------------------------------------------------------");
                     fp = fopen("clinic.txt", "a");   
                  fprintf(fp, "-------------------------------\n");
                  fprintf(fp, "Baby Name     : %s\n", records[recordindex].name);
                  fprintf(fp, "Blood Group   : %s\n", records[recordindex].bloodgroup);
                  fprintf(fp, "Parent Name   : %s\n", records[recordindex].parent);
                  fprintf(fp, "Contact No    : %s\n", records[recordindex].contact);
                  fprintf(fp, "Service Used  : %d\n", menuchoice);
                  fprintf(fp, "-------------------------------\n\n");
                  fclose(fp);
                     recordindex++;
                     break;
          case 4: printf("\n=============================================================");
                  printf("\n\nEnter baby's name : ");
                  scanf("%s",&records[recordindex].name);
                  printf("\nEnter Blood group of baby :");
                  scanf("%s",&records[recordindex].bloodgroup);
                  printf("\nEnter Parent name : ");
                  scanf("%s",records[recordindex].parent);
                  printf("\nEnter Parent contact number : ");
                  scanf("%s",&records[recordindex].contact);
                  printf("\n==========================================================");
                  printf("\n                LABORATORY SERVICES                        ");
                  printf("\n===========================================================");
                  printf("\n1.Collect reports");
                  printf("\n2. Perform Lab Tests");
                  printf("\nEnter the laboratory service needed : ");
                  scanf("%d",&labchoice);
                  switch(labchoice)
                  {
                     case 1:printf("\n\n=========================================================");
                            printf("\nREPORT TO THE CLINIC BETWEEN 1:00 PM TO 4:00 PM");
                            printf("\n=========================================================");
                             fprintf(fp, "-------------------------------\n");
                            fprintf(fp, "Baby Name     : %s\n", records[recordindex].name);
                            fprintf(fp, "Blood Group   : %s\n", records[recordindex].bloodgroup);
                            fprintf(fp, "Parent Name   : %s\n", records[recordindex].parent);
                            fprintf(fp, "Contact No    : %s\n", records[recordindex].contact);
                            fprintf(fp, "Service Used  : %d\n", menuchoice);
                            fprintf(fp, "-------------------------------\n\n");
                            fclose(fp);
                            
                            break;
                    case 2:printf("\n==========================================================");
                           printf("\n                  LABORATORY TESTS                        ");
                           printf("\n=========================================================");
                           printf("\n1.Blood and urine test");
                           printf("\n2.Sonography (ultrasound)");
                           printf("\n3.ECG");
                           printf("\n4.MRI");
                           printf("\n5.CT scan");
                           printf("\nEnter the Test to be performed : "); 
                           scanf("\n%d",&test);
                           printf("\n\nEnter 1 to book appointment and Enter 0 to book appointment later\n");
                           scanf("%d",&choice);
                           printf("\n=========================================================");
                 if(choice==1)
                 {
                     printf("\nAvailable Time Slots for Laboratry Tests");
                     printf("\n=========================================================");
                     for(int i=0;i<10;i++)
                     {
                         if(labSlots[i].booked == 0)
                         {
                              printf("\n%d. %s | %s | %s\n",
                                 i+1,
                                 labSlots[i].day,
                                 labSlots[i].date,
                                 labSlots[i].time);
                         }
                     }
                     printf("\n\nEnter Slot Option Number = ");
                     scanf("%d",&slot);
                     labSlots[slot - 1].booked = 1;
                     printf("\n=========================================================");
                     printf("\nYOUR APPOINTMENT IS BOOKED");
                     printf("\nREPORT TO THE CLINIC 15 mins PRIOR TO SELECTED SLOT");
                     printf("\nThank you");
                     printf("\n=========================================================");
                  }
                  else
                  {
                      printf("\nThank you");
                  } 
                  break;
                  default:printf("\nInvalid Entry");
                  }
                  fp = fopen("clinic.txt", "a");   
                  fprintf(fp, "-------------------------------\n");
                  fprintf(fp, "Baby Name     : %s\n", records[recordindex].name);
                  fprintf(fp, "Blood Group   : %s\n", records[recordindex].bloodgroup);
                  fprintf(fp, "Parent Name   : %s\n", records[recordindex].parent);
                  fprintf(fp, "Contact No    : %s\n", records[recordindex].contact);
                  fprintf(fp, "Service Used  : %d\n", menuchoice);
                  if (choice==1)
                  {
                    fprintf(fp, "Appointment Status : BOOKED\n");
                    fprintf(fp, "Appointment Slot   : %d\n", slot);
                    fprintf(fp, "Appointment Day    : %s\n", labSlots[slot-1].day);
                    fprintf(fp, "Appointment Date   : %s\n", labSlots[slot-1].date);
                    fprintf(fp, "Appointment Time   : %s\n", labSlots[slot-1].time);
                  }
                  else
                  {
                     fprintf(fp, "Appointment Status : NOT BOOKED\n");
                  }
                  fprintf(fp, "-------------------------------\n\n");
                  fclose(fp);
                  recordindex++;
                  break; 
                
          case 5:printf("\n=============================================================");
                  printf("\n\nEnter baby's name : ");
                  scanf("%s",&records[recordindex].name);
                  printf("\nEnter Blood group of baby :");
                  scanf("%s",&records[recordindex].bloodgroup);
                  printf("\nEnter Parent name : ");
                  scanf("%s",records[recordindex].parent);
                  printf("\nEnter Parent contact number : ");
                  scanf("%s",&records[recordindex].contact);
                  printf("\n==========================================================");
                  printf("\n                 DENTAL CARE SERVICES                     ");
                  printf("\n==========================================================");
                  printf("\n1.Routine checkup");
                  printf("\n2.Filling");
                  printf("\n3.Root Canal and cap");
                  printf("\n4.Tooth extraction");
                  printf("\n5.Space maintainers");
                  printf("\nEnter Dental care required : ");
                  scanf("%d",&dental);
                  printf("\n\nEnter 1 to book appointment and Enter 0 to book appointment later\n");
                  scanf("%d",&choice);
                  printf("\n=========================================================");
                  if(choice==1)
                  {
                     printf("\nAvailable Time Slots for Dental Care");
                     printf("\n=========================================================");
                     for(int i=0;i<10;i++)
                     {
                         if(dentalSlots[i].booked == 0)
                         {
                              printf("\n%d. %s | %s | %s\n",
                                 i+1,
                                 dentalSlots[i].day,
                                 dentalSlots[i].date,
                                 dentalSlots[i].time);
                         }
                     }
                     printf("\n\nEnter Slot Option Number = ");
                     scanf("%d",&slot);
                     dentalSlots[slot - 1].booked = 1;
                     printf("\n=========================================================");
                     printf("\nYOUR APPOINTMENT IS BOOKED");
                     printf("\nREPORT TO THE CLINIC 15 mins PRIOR TO SELECTED SLOT");
                     printf("\nThank you");
                     printf("\n=========================================================");
                  }
                  else
                  {
                      printf("\nThank you");
                  } 
                  fp = fopen("clinic.txt", "a");   
                  fprintf(fp, "-------------------------------\n");
                  fprintf(fp, "Baby Name     : %s\n", records[recordindex].name);
                  fprintf(fp, "Blood Group   : %s\n", records[recordindex].bloodgroup);
                  fprintf(fp, "Parent Name   : %s\n", records[recordindex].parent);
                  fprintf(fp, "Contact No    : %s\n", records[recordindex].contact);
                  fprintf(fp, "Service Used  : %d\n", menuchoice);
                  if (choice==1)
                  {
                    fprintf(fp, "Appointment Status : BOOKED\n");
                    fprintf(fp, "Appointment Slot   : %d\n", slot);
                    fprintf(fp, "Appointment Day    : %s\n", dentalSlots[slot-1].day);
                    fprintf(fp, "Appointment Date   : %s\n", dentalSlots[slot-1].date);
                    fprintf(fp, "Appointment Time   : %s\n", dentalSlots[slot-1].time);
                  }
                  else
                  {
                     fprintf(fp, "Appointment Status : NOT BOOKED\n");
                  }
                  fprintf(fp, "-------------------------------\n\n");
                  fclose(fp);
                  recordindex++;
                  break;
               case 6:
                     
                   {
                       int service, delSlot;
                       printf("\n=========================================================");
                       printf("\nDELETE APPOINTMENT");
                       printf("\n=========================================================");
                       printf("\nEnter baby's name : ");
                       scanf("%s", name);
                       printf("\nSelect Service Type");
                       printf("\n1. Vaccination");
                       printf("\n2. Routine Checkup");
                       printf("\n3. Laboratory");
                       printf("\n4. Dental");
                       printf("\nEnter choice : ");
                       scanf("%d", &service);
                       printf("\nEnter slot number to delete : ");
                       scanf("%d", &delSlot);
                        if(service == 1)
                        vaccinationSlots[delSlot-1].booked = 0;
                        else if(service == 2)
                        routineSlots[delSlot-1].booked = 0;
                        else if(service == 3)
                        labSlots[delSlot-1].booked = 0;
                        else if(service == 4)
                        dentalSlots[delSlot-1].booked = 0;
                        fp = fopen("clinic.txt", "a");
                        fprintf(fp, "Appointment for %s is DELETED\n", name);
                        fprintf(fp, "--------------------------------\n\n");
                        fclose(fp);
                        printf("\nAppointment deleted successfully");
                   } 
                      break;
          case 7 : printf("\n=========================================================");
                   printf("\nEXITING THE SYSTEM.") ; 
                   printf("\nTHANK YOU FOR VISITING.") ; 
                   printf("\n=========================================================");
                   break;
          default: printf("Invalid choice , please try again");
      }
      printf("\nEnter 2 to continue and 0 to exit system\n");
      scanf("%d",&num);
}while(num!=0); 
    return 0;   
}