#include "myobject.h"

/* in myobject.c */
/**
* Define newly Created custom type So that further we can use this as type of variable
*/ 
G_DEFINE_TYPE(MyObject, my_object, G_TYPE_OBJECT);

/* in myobject.c */
/**
* these 2 static function some time required ??? why ?? TODO
*/
static void my_object_class_init(MyObjectClass *_class) 
{
     /* code */
}
 
static void my_object_init(MyObject* obj)
{
     /* code */
}

/* in myobject.c */
/**
* myobject constructure
*/ 
GObject* my_object_new(void)
{
     return g_object_new(MY_TYPE_OBJECT , 0);
}

