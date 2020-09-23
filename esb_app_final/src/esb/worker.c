#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include <unistd.h>

#include "../DB-ACCESS/db_connection.h"

#include<mysql/mysql.h>

#include "../BMD/xml_header.h"

#include "../endpoint/transform.h"

#include <pthread.h>


void * poll_database_for_new_requests(void * vargp) {
  sleep(7);
  // Step 1: Open a DB connection
  int i = 0;
  while (i < 1) {


    task_list * req = fetch_data1();
    if (req == NULL) {
      printf("no request\n");
    }

    if (req != NULL) {

      int route_id = select_active_routes(req -> MessageType, req -> Sender, req -> Destination);
      char * data_location = req -> data_location;
      //printf("%s",b->payload);
      tp_data * n1 = get_tp_data(route_id);
      //tf_data* n2 = get_tf_data(route_id);
      char * transport_key = strdup(n1 -> config_k);
      char * transport_value = strdup(n1 -> config_v);
      printf("%s\n", n1 -> config_k);
      printf("%s\n", n1 -> config_v);
      free(n1);
      // printf("%s\n",n2->config_key);
      // printf("%s\n",n2->config_value);
      tf_data * n2 = get_tf_data(route_id);
      char * transform_key = strdup(n2 -> config_key);
      char * transform_value = strdup(n2 -> config_value);
      printf("%s", transform_key);
      printf("%s\n", transform_value);
      free(n2);
      

      char * fields[1]; //url

      printf("Applying transformation and transporting steps. \n");

      apply_transform(transform_key, transport_key, transport_value, data_location, fields);

      // char* transformed_string="https://ifsc.razorpay.com/HDFC0CAGSBK";
      if (!strcmp(transport_key, "HTTP")) {
        printf("%d\n", strcmp(fields[0], "https://ifsc.razorpay.com/HDFC0CAGSBK"));
        char url2[100];
        strcpy(url2, fields[0]);
        printf("sending http request\n");
        printf("%s\n", url2);

        int httpres;
        httpres =  http_request(fields[0]);
        if (httpres == -1) {
          printf("Connection Failed");
          update_status("received", req -> id);
        } else {
          update_status("done", req -> id);
          printf("DONE\n");
        }

      } else if (!strcmp(transport_key, "SMTP")) {

        int x = sendemail("riyatoteja1998@gmail.com", "/home/riya/ganga/esb_app/src/esb/data-Payload.json");
        if (x == 1) {
          printf("mail sent successfully");
          update_status("done", req -> id);
          printf("DONE\n");
        } else printf("could not send mail");

      }

      
      printf("Applied transformation and transporting steps.\n");

    }
    printf("Sleeping for 7 seconds.\n");
    sleep(7);
  }
  return (void*)1;
}



