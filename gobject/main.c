#include <stdio.h>

#include "myobject.h"

int main(int argc, char *argv[]){
	GObject* myobj = my_object_new(); 
	g_object_unref(myobj);
	return 0;
}
