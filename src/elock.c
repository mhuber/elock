#include <stdio.h>
#include <libintl.h>
#include <Ecore.h>
#include <Ecore_Evas.h>
#include <Evas.h>
#include <Edje.h>

Ecore_Evas *main_win;

static void
key_handler(void *data, Evas *evas, Evas_Object *obj, void *event_info)
{
	printf("key pressed\n");
	ecore_evas_hide(main_win);
}

int main(int argc, char **argv)
{
	evas_init();
	ecore_init();
	ecore_evas_init();
	edje_init();

	setlocale(LC_ALL, "");
	textdomain("elock");

	//Ecore_Evas *
	main_win = ecore_evas_software_x11_new(0, 0, 0, 0, 600, 800);
	ecore_evas_borderless_set(main_win, 0);
	ecore_evas_shaped_set(main_win, 0);
	ecore_evas_title_set(main_win, "elock");
	ecore_evas_name_class_set(main_win, "elock", "elock");
	//ecore_evas_show(main_win);

	Evas *main_canvas = ecore_evas_get(main_win);

	Evas_Object *edje = edje_object_add(main_canvas);
	evas_object_name_set(edje, "edje");
	edje_object_file_set(edje, "themes/elock.edj", "elock");
	evas_object_move(edje, 0, 0);
	evas_object_resize(edje, 600, 800);
	evas_object_event_callback_add(edje, EVAS_CALLBACK_KEY_UP, key_handler, NULL);
	evas_object_show(edje);

	char *t1 = gettext("Press and hold \"OK\" for 3-4 seconds to unlock the device");
	edje_object_part_text_set(edje, "elock/label", t1);

	edje_object_signal_emit(edje, "set_batt_full", "");


	ecore_evas_show(main_win);
	ecore_main_loop_begin();

	edje_shutdown();
	ecore_evas_shutdown();
	ecore_shutdown();
	evas_shutdown();

	return 0;
}
