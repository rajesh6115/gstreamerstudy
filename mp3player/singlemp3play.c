/* example-begin helloworld.c */
#include <gst/gst.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
	GstElement *pipeline, *filesrc, *audioparser, *decoder, *audioconverter, *audiosink;
	gst_init(&argc, &argv);
	if (argc != 2) {
		g_print ("usage: %s <mp3 filename>\n", argv[0]);
		exit (-1);
	}
	/* create a new pipeline to hold the elements */
	pipeline = gst_pipeline_new ("pipeline");
	/* create a disk reader */
	filesrc = gst_element_factory_make ("filesrc", "disk_source");
	g_object_set (G_OBJECT (filesrc), "location", argv[1], NULL);
	audioparser = gst_element_factory_make ("mpegaudioparse" , "mp3audioparser");
	audioconverter = gst_element_factory_make ("audioconvert", "sinkaudioconvert");
	/* now it’s time to get the decoder */
	decoder = gst_element_factory_make ("avdec_mp3", "decoder");
	/* and an audio sink */
	audiosink = gst_element_factory_make ("autoaudiosink", "play_audio");
	/* add objects to the main pipeline */
	gst_bin_add_many (GST_BIN (pipeline), filesrc, audioparser, decoder, audioconverter, audiosink, NULL);
	/* link src to sink */
	gst_element_link_many (filesrc, audioparser, decoder, audioconverter, audiosink, NULL);
	/* start playing */
	gst_element_set_state (pipeline, GST_STATE_PLAYING);
	//while (gst_bin_iterate (GST_BIN (pipeline))); // removed as pipe can iterate by there own so enter to GMainloop or Wait
	sleep(300);
	/* stop the pipeline */
	gst_element_set_state (pipeline, GST_STATE_NULL);
	/* we don’t need a reference to these objects anymore */
	gst_object_unref (GST_OBJECT (pipeline));
	/* unreffing the pipeline unrefs the contained elements as well */
	exit (0);
}
/* example-end helloworld.c */
