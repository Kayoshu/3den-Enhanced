/*
	Author: Revo

	Description:
	Removes weapons from selected units and saves their inventory.

	Parameter(s):
	-
	Returns:
	BOOLEAN - true / false
*/

private _units = get3DENSelected "Object";

if (count _units == 0 || !is3DEN) exitWith {false};

collect3DENHistory
{
	{
		removeAllWeapons _x;
	} forEach _units;
	save3DENInventory _units;
};

["Enh_actionPerformed"] call BIS_fnc_3DENNotification;

true