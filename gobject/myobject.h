#include <glib-object.h>
/**
* Boiler-Plate Code (make standardised code to with glib standard)
* Since the GObject System is just a third-party library and 
* therefore cannot make any changes to the C Language itself, 
* creating a new object requires a lot of boiler-plate code
*/
#define MY_TYPE_OBJECT                   (my_object_get_type ())
#define MY_OBJECT(obj)                   (G_TYPE_CHECK_INSTANCE_CAST ((obj), MY_TYPE_OBJECT, MyObject))
#define MY_IS_OBJECT(obj)                (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MY_TYPE_OBJECT))
#define MY_OBJECT_CLASS(_class)          (G_TYPE_CHECK_CLASS_CAST ((_class), MY_TYPE_OBJECT, MyObjectClass))
#define MY_IS_OBJECT_CLASS(_class)       (G_TYPE_CHECK_CLASS_TYPE ((_class), MY_TYPE_OBJECT))
#define MY_OBJECT_GET_CLASS(obj)         (G_TYPE_INSTANCE_GET_CLASS ((obj), MY_TYPE_OBJECT, MyObjectClass))
/* in myobject.h */
typedef struct _MyObject MyObject;
typedef struct _MyObjectClass MyObjectClass;
 
struct _MyObject
{
  GObject parent_instance;
 
  /* instance members */
};
 
struct _MyObjectClass
{
  GObjectClass parent_class;
 
  /* class members */
};
