/*
 *  Copyright (c) 2013 Stefan Taferner <stefan.taferner@gmx.at>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 */
#ifndef rmgira_app_h
#define rmgira_app_h

/**
 * Der Timer ist übergelaufen.
 */
extern void timer_event();

/**
 * Alle Applikations-Parameter zurücksetzen.
 */
extern void restart_app();

/**
 * Befehle an den Rauchmelder senden und Antworten verarbeiten.
 */
extern void process_commands();


#endif /*rmgira_app_h*/
