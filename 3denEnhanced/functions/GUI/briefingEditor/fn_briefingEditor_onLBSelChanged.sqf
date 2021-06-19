/*
  Author: R3vo

  Date: 2019-06-20

  Description:
  Used by ENH_BriefingEditor GUI. Triggers when HTML tag combo selection has changed.

  Parameter(s):
  0: CONTROL - Combo box control
  1: NUMBER - Selected index

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;

params ["_ctrlCombo", "_selectedIndex"];

private _display = ctrlParent _ctrlCombo;

private _ctrlFirstParam = CTRL(IDC_BRIEFINGEDITOR_FIRSTPARAM);
private _ctrlFirstParamValue = CTRL(IDC_BRIEFINGEDITOR_FIRSTPARAMVALUE);
private _ctrlSecondParam = CTRL(IDC_BRIEFINGEDITOR_SECONDPARAM);
private _ctrlSecondParamValue = CTRL(IDC_BRIEFINGEDITOR_SECONDPARAMVALUE);
private _ctrlThirdParam = CTRL(IDC_BRIEFINGEDITOR_THIRDPARAM);
private _ctrlThirdParamValue = CTRL(IDC_BRIEFINGEDITOR_THIRDPARAMVALUE);
private _ctrlLBColours = CTRL(IDC_BRIEFINGEDITOR_COLOURS);
private _ctrlLBFonts = CTRL(IDC_BRIEFINGEDITOR_FONTS);
private _ctrlLBMarkers = CTRL(IDC_BRIEFINGEDITOR_MARKERS);

private _fnc_setupCtrls =
{
  params [["_states", [true, true, true]], ["_texts", ["", "", ""]], ["_lbStates", [false, false, false]], ["_defaults", ["", "", ""]]];
  {
    _x ctrlShow (_states # _forEachIndex);
    _x ctrlSetText (_defaults # _forEachIndex);
  } forEach [_ctrlFirstParamValue, _ctrlSecondParamValue, _ctrlThirdParamValue];
  {
    _x ctrlSetText localize (_texts # _forEachIndex);
  } forEach [_ctrlFirstParam, _ctrlSecondParam, _ctrlThirdParam];
  {
    _x ctrlShow (_lbStates # _forEachIndex);
  } forEach [_ctrlLBMarkers, _ctrlLBColours, _ctrlLBFonts];
};

switch (_selectedIndex) do
{
  case 0:
  {
    [[false, false, false], ["", "", ""], [false, false, false]] call _fnc_setupCtrls;
  };
  case 1:
  {
    [[false, false, false], ["Marker", "", ""], [true, false, false]] call _fnc_setupCtrls;
  };
  case 2:
  {
    [[true, true, true], ["STR_ENH_BRIEFINGEDITOR_PATH", "STR_ENH_BRIEFINGEDITOR_WIDTH", "STR_ENH_BRIEFINGEDITOR_HEIGHT"], [false, false, false], ["", "300", "150"]] call _fnc_setupCtrls;
  };
  case 3:
  {
    [[true, false, false], ["STR_ENH_BRIEFINGEDITOR_SIZE", "", ""], [false, true, true]] call _fnc_setupCtrls;
  };
  case 4;
  case 5:
  {
    [[true, false, false], ["STR_ENH_BRIEFINGEDITOR_EXPRESSION", "", ""]] call _fnc_setupCtrls;
  };
};