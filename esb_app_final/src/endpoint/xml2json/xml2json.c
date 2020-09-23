#include <stdio.h>

#include <libxml/parser.h>

#include <libxml/tree.h>

#include <sys/types.h>

#include <unistd.h>

#include<string.h>


/* 
takes in xml file and uses libxml to convert it in a tree like data structure and then prints in json format using libxml.
how to run:-
gcc -Wall -I/usr/include/libxml2 -o xml2json xml2json.c -lxml2*/

//checks whether a node is leaf node

int is_leaf2(xmlNode * node) {
  xmlNode * child = node -> children;
  while (child) {
    if (child -> type == XML_ELEMENT_NODE) return 0;

    child = child -> next;
  }

  return 1;
}


void xml2json(xmlNode * node, int indent_len, char json[]) {
  char s[100];
  int i = 0;
  while (node) {
    if (node -> type == XML_ELEMENT_NODE) {
      if (is_leaf2(node)) {
        i++;

        printf( "%*c\"%s\": \"%s\"", indent_len * 2, ' ', node -> name, xmlNodeGetContent(node));
       // strcat(json, s);
        if (node -> next -> next) printf( "%s", ",\n");
        else printf( "%s", "\n");
        //strcat(json, s);
      } else {

        printf( "%*c\"%s\": {\n", indent_len * 2, ' ', node -> name);
        //strcat(json, s);
        xml2json(node -> children, indent_len + 1, json);
        if (!node -> next) {
          printf( "%*c\n", (indent_len + 1) * 2 - 1, '}');
          //strcat(json, s);
        } else if (node -> next -> next) {
          printf( "%*c,\n", (indent_len + 1) * 2 - 1, '}');
          //strcat(json, s);
        } else {
          printf("%*c\n", (indent_len + 1) * 2 - 1, '}');
          //strcat(json, s);
        }
      }
    }
    //print_xml(node->children, indent_len + 1);

    node = node -> next;
  }
  //if(i>1)printf("%*c,\n", indent_len*2 -1,'}');
  //else printf("%*c\n", indent_len*2 -1,'}');

}

void xml_to_json(char * xml_file, char * json_file) {
  char json[1000] = "{\n";
  xmlDoc * doc = NULL;
  xmlNode * root_element = NULL;
  char json_string[1000] = "";
  doc = xmlReadFile(xml_file, NULL, 0);

  if (doc == NULL) {
    printf("invalid format XML file");
  } else {
    root_element = xmlDocGetRootElement(doc);
    xml2json(root_element, 1, json_string);
    //FILE * fptr;
    //fptr = fopen(json_file, "w");
    printf( "{\n");
    //fprintf(fptr, "%s", json_string);
    printf("%s", json_string);
    printf( "}\n");
    //fclose(fptr);
  }

  xmlFreeDoc(doc);
  xmlCleanupParser();

  printf("file generated successfully\n");

}
void xml2json2(char Pay[])
{
	char *filename="payload.json";

        FILE *file;
    	file = fopen(filename,"w");
    	
    	if(file == NULL) 
    	{
        	printf("file opening failed");
        	exit(0);
    	}
    	
    	fprintf(file,"{\n \"Payload\":\"%s\"\n}",Pay);
    	
    	printf("\nPayload json File created\n");
    

    	fclose(file);
      
}
/*
 
int main(){
  char* input="bmd.xml";
  char * output="bmd2.json";
  printf("%s generated successfully", output);
  xml_to_json(input, output);
  return 0;


}
*/


