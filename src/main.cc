//$Id: main.cc 836 2007-05-09 03:02:38Z jjongsma $ -*- c++ -*-

/* gtkmm example Copyright (C) 2002 gtkmm development team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <gtkmm.h>
#include <iostream>

Gtk::Window* mainWindow = 0;

int main(int argc, char *argv[]) {
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv,
			"net.cjb.juan64.gtweetdeck");

	Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
	try {
		refBuilder->add_from_file("glade/main.glade");
	} catch (const Glib::FileError& ex) {
		std::cerr << "FileError: " << ex.what() << std::endl;
		return 1;
	} catch (const Glib::MarkupError& ex) {
		std::cerr << "MarkupError: " << ex.what() << std::endl;
		return 1;
	} catch (const Gtk::BuilderError& ex) {
		std::cerr << "BuilderError: " << ex.what() << std::endl;
		return 1;
	}

	refBuilder->get_widget("mainWindow", mainWindow);
	if (mainWindow) {
		//Get the GtkBuilder-instantiated Button, and connect a signal handler:
//		Gtk::Button* pButton = 0;
//		refBuilder->get_widget("quit_button", pButton);
//		if (pButton) {
//			pButton->signal_clicked().connect(sigc::ptr_fun(on_button_clicked));
//		}

		app->run(*mainWindow);
		delete mainWindow;
	}

	return 0;
}
