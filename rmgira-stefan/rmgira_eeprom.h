/*
 *  Copyright (c) 2013 Stefan Taferner <stefan.taferner@gmx.at>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 */

//-----------------------------------------------------------------------------
// ETS VD Konfigurations-Parameter
// Zugriff auf diese Parameter über das globale Array eeprom[]
//-----------------------------------------------------------------------------

/**
 * 0x80 - Alarm zyklisch senden aktiviert
 * 0..0x7f - Intervall für zyklisches Senden (siehe CONF_A_BASIS)
 */
#define CONF_A_ZYKLISCH 	250

/**
 * Obsolet, verwende CONF_A_ZYKLISCH
 */
#define CONF_A_FAKTOR		250

/**
 * Zeitbasis für Alarm zyklisch senden.
 * Wenn 0 dann enthält CONF_A_FAKTOR Sekunden, sonst Minuten
 */
#define CONF_A_BASIS		251

/**
 * 0x80 - Testalarm zyklisch senden aktiviert
 * 0..0x7f - Intervall für zyklisches Senden (siehe CONF_S_BASIS)
 */
#define CONF_S_ZYKLISCH 	246

/**
 * Obsolet, verwende CONF_S_ZYKLISCH
 */
#define CONF_S_FAKTOR		246

/**
 * Zeitbasis für Testalarm zyklisch senden.
 * Wenn 0 dann enthält CONF_S_ZYKLISCH Sekunden, sonst Minuten
 */
#define CONF_S_BASIS		247

/**
 * 0x80 - Alarm verzögert senden aktiviert
 * 0..0x7f - Verzögerung (siehe CONF_A_DELAY_BASIS)
 */
#define CONF_A_DELAY		248

/**
 * Obsolet, verwende CONF_A_DELAY
 */
#define CONF_A_DELAY_FAKTOR	248

/**
 * Zeitbasis für Alarm verzögert senden.
 * Wenn 0 dann enthält CONF_A_DELAY Sekunden, sonst Minuten
 */
#define CONF_A_DELAY_BASIS	249

/**
 * 0x80 - Info Com-Objekte zyklisch senden
 * 0..0x7f - Intervall für zyklisches Senden (siehe CONF_INFO_BASIS)
 */
#define CONF_INFO_ZYKLISCH	244

/**
 * Obsolet, verwende CONF_INFO_ZYKLISCH
 */
#define CONF_INFO_FAKTOR	244

/**
 * Zeitbasis für Info Com-Objekte zyklisch senden.
 * Wenn 0 dann enthält CONF_INFO_ZYKLISCH Sekunden, sonst Minuten
 */
#define CONF_INFO_BASIS		245

/**
 * Bits aktivieren das zyklische Senden der Com-Objekte 4..10
 */
#define CONF_INFO_4TO10		252

/**
 * Bits aktivieren das zyklische Senden der Com-Objekte 11..17
 */
#define CONF_INFO_11TO17	253
