/* See LICENSE file for copyright and license details. */

/* alsa sound */
static const char channel[]   = "Master";

/* battery */
static const char batterypath[] = "/sys/class/power_supply/";
static const char batterynow[]  = "energy_now";
static const char batteryfull[] = "energy_full_design";

/* bar update interval in seconds (smallest value = 1) */
static unsigned int update_interval = 1;

/* statusbar
- get_battery (battery percentage) [argument: battery name]
- cpu_temperature (cpu temperature in degrees) [argument: temperature file]
- cpu usage (cpu usage in percent)
- datetime (date and time) [argument: format]
- diskusage (disk usage in percent) [argument: mountpoint]
- ram_usage (ram usage in percent)
- volume (alsa volume and mute status in percent) [argument: soundcard]
- wifi_signal (wifi signal in percent) [argument: wifi card interface name] */
static const struct arg args[] = {
    /* function     format          argument */
    { wifi_perc,    "wifi %4s | ",  "wlp3s0" },
    { battery_perc, "bat %4s | ",   "BAT0" },
    { cpu_perc,     "cpu %4s ",     NULL },
    { temp,         "%3s | ",       "/sys/devices/platform/coretemp.0/hwmon/hwmon2/temp1_input" },
    { ram_perc,     "ram %3s | ",   NULL },
    { vol_perc,     "vol %4s | ",   "default" },
    { disk_perc,    "ssd %3s | ",   "/" },
    { datetime,     "%s",           "%y-%m-%d %H:%M:%S" },
};
