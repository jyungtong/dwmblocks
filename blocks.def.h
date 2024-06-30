//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"🎧", "~/get_volume.sh",	0,		10},
	{"🌡️", "echo $(($(cat /sys/class/thermal/thermal_zone6/temp) / 1000))\"°C\"",	5,		0},
	{"", "top -bn1 | grep \"Cpu(s)\" | sed \"s/.*, *\\([0-9.]*\\)%* id.*/\\1/\" | awk '{printf \"🖥️%5.1f%%\", 100 - $1}'",	3,		0},
	{"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	5,		0},
	{"🔋", "echo $(cat /sys/class/power_supply/BAT0/capacity)\"%\"",	5,		0},
	{"", "date '+%b %d (%a) %T'",					1,		0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
