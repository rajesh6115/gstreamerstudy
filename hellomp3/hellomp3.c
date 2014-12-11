/**
 pipeline got from youtube vidio and modified hello tutorial code
 TOCOMPILE: 
	gcc hellomp3.c `pkg-config gstreamer-1.0 --cflags --libs` -o hellomp3
**/

#include <gst/gst.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	GError *err= NULL; // For Storing Error through by gstreamer
	GstElement *pipeline;
	GstBus *bus;
	GstMessage *msg;
	gboolean retvalue;
	//gst_init(&argc, &argv); // Initilise The Frame Woork
	//retvalue = gst_init_check(&argc, &argv, &err);
	retvalue = gst_init_check(NULL, NULL, &err);
	if(retvalue){
		printf("gstreamer Initilised properly\n");
	}else{
		printf("gstreamer not able to initilise error %s \n Exiting...\n", err? err->message:"none");
		return -1;
	}
	if(err){
		printf("Freeing Previous Error\n");
		g_error_free (err);
		err=NULL;
	}
	/*Build Pileline */
	//gst-launch-1.0 audiotestsrc ! audioconvert ! autoaudiosink 
	//pipeline = gst_parse_launch("audiotestsrc ! audioconvert ! autoaudiosink ", &err);
	//ddtb.mp3
	//gst-launch-0.10 filesrc location=xyz.mp3 ! decodebin2 ! audioconvert ! autoaudiosink
	// change location=<mp3 file path>
	pipeline = gst_parse_launch("filesrc location=/home/rajesh/Music/ddtb.mp3 ! mpegaudioparse ! avdec_mp3 ! audioconvert ! autoaudiosink", &err);
	/* Start playing */
	gst_element_set_state (pipeline, GST_STATE_PLAYING);
	/* Wait until error or EOS */
	bus = gst_element_get_bus (pipeline);
	msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

	/* Free resources */
	if (msg != NULL)
		gst_message_unref (msg);
	gst_object_unref (bus);
	gst_element_set_state (pipeline, GST_STATE_NULL);
	gst_object_unref (pipeline);
	gst_deinit(); // deinitialise all normally not required
}
