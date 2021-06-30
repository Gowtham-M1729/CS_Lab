#include <malloc.h> 
#include <stdio.h> 
struct link { 
	int info; 
	struct link* next; 
}; 

struct link* start = NULL;  
struct link* create_header_list(int data) 
{
	struct link *new_node, *node; 
	new_node = (struct link*) 
		malloc(sizeof(struct link)); 
	new_node->info = data; 
	new_node->next = NULL; 
	if (start == NULL) {
		start = (struct link*) 
			malloc(sizeof(struct link));
                start->info =0;
		start->next = new_node; 
	} 
	else {
		node = start; 
		while (node->next != NULL) { 
			node = node->next;
	     } 
		node->next = new_node; 
	}
        start->info=start->info+1;
	return start; 
} 
struct link* display() 
{ 
	struct link* node; 
	node = start; 
        printf("%d ", node->info);
	node = node->next; 
	while (node != NULL) { 
		printf("%d ", node->info); 
		node = node->next; 
	} 
	printf("\n"); 
	return start; 
}
int main() 
{
	create_header_list(11); 
	create_header_list(12); 
	create_header_list(13); 
	display(); 
	create_header_list(14); 
	create_header_list(15);  
	display();
	return 0; 
}

