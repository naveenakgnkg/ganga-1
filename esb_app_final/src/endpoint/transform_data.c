#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <memory.h>

#include "../BMD/xml_header.h"

void apply_transform(char * transform_type, char * transport_key, char * transport_value, char * data_location,char* fields2[]) {
  
  char * payload=extract_payload(data_location);
  char payload2[1000];
  strcpy(payload2,payload);
  if ((!strcmp(transform_type, ":IFSC_CODE")) && (!strcmp(transport_key, "HTTP"))) {
    printf("append payload to transport_value i.e. URL\n");
    
    for(int i=0;i<strlen(payload2);i++){	
        char ch = payload2[i];
	strncat(transport_value, &ch, 1);
    }

    fields2[0]=transport_value;

  } else if ((!strcmp(transform_type, "JSON")) && (!strcmp(transport_key, "SMTP"))) {
    printf("converted payload to json file\n");
    
    

  } else {
    printf("No transformation needed\n");


  }

}
    
