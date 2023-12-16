class Display3DEN
{
  class ContextMenu: ctrlMenu
  {
    class Items
    {
      #include "contextMenu.hpp"
    };
  };
  class Controls
  {
    class StatusBar: ctrlControlsGroupNoScrollbars
    {
      class Controls
      {
        class TextX: ctrlStaticPicture
        {
          colorText[] = {COLOR_POSX_RGBA};
        };
        class ValueX: ctrlEdit
        {
          w = 19 * GRID_W;
        };
        class Version: ctrlButton
        {
          idc = -1;
          text = "V";
          x = ORIGIN_X_STATUSBAR - 15 * GRID_W - SPACE_X;
          y = 2 * pixelH;
          w = 4 * GRID_W - 4 * pixelW;
          h = 4 * GRID_H - 4 * pixelH;
          colorBackground[] = {0, 0, 0, 0.5};
          onLoad = "_this # 0 ctrlSetToolTip format ['%1.%2', (productVersion select 2) * 0.01 toFixed 2, productVersion select 3]";
          onButtonClick = "call ENH_fnc_productInfo";
        };
        class TextY: TextX
        {
          x = 22 * GRID_W;
          colorText[] = {COLOR_POSY_RGBA};
        };
        class ValueY: ValueX
        {
          x = 25 * GRID_W;
        };
        class TextZ: TextX
        {
          x = 44 * GRID_W;
          colorText[] = {COLOR_POSZ_RGBA};
        };
        class ValueZ: ValueX
        {
          x = 47 * GRID_W;
        };
        class TextDis: TextX
        {
          x = 66 * GRID_W;
          colorText[] = {1, 1, 1, 1};
        };
        class ValueDis: ValueX
        {
          x = 69 * GRID_W;
        };
        class ENH_TextDir: TextX
        {
          idc = IDC_STATUSBAR_CAMDIR_ICON;
          x = 99 * GRID_W;
          text = "\a3\3den\data\attributes\loiterdirection\ccw_ca.paa";
          colorText[] = {1, 1, 1, 1};
        };
        class ENH_ValueDir: ValueX
        {
          idc = IDC_STATUSBAR_CAMDIR;
          x = 102 * GRID_W;
          w = 9 * GRID_W;
          onLoad = "(_this # 0) ctrlEnable false";
          style = ST_CENTER + ST_NO_RECT;
        };
        #if __has_include("\userconfig\ENH_Config.hpp")
        class ENH_UserconfigWarning: ENH_TextDir
        {
          x = 114 * GRID_W;
          text = "\a3\ui_f\data\map\markers\military\warning_ca.paa";
          tooltip = "$STR_ENH_STATUSBAR_USERCONFIG_WARNING_TOOLTIP";
        };
        #endif
        #ifndef ENH_HIDE_INTERFACE
        class ENH_SessionTime: ENH_TextDir
        {
          idc = IDC_STATUSBAR_SESSIONTIMER;
          text = "a3\modules_f_curator\data\portraitskiptime_ca.paa";
          x = ORIGIN_X_STATUSBAR - 11 * GRID_W - 2 * SPACE_X;
          y = 2 * pixelH;
        };
        class ENH_NumberMarkers: ValueY
        {
          idc = IDC_STATUSBAR_NUMMARKERS;
          x = ORIGIN_X_STATUSBAR - 22 * GRID_W - 2 * SPACE_X;
          //y = 2 * pixelH;
          w = 7 * GRID_W;
          //h = 4 * GRID_H - 4 * pixelH;
          onLoad = "(_this # 0) ctrlShow false; (_this # 0) ctrlEnable false";
          style = ST_CENTER + ST_NO_RECT;
        };
        class ENH_IconMarkers: ENH_TextDir
        {
          idc = IDC_STATUSBAR_ICONMARKERS;
          x = ORIGIN_X_STATUSBAR - 25 * GRID_W - 2 * SPACE_X;
          onLoad = "(_this # 0) ctrlShow false";
          text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeMarkers_ca.paa";
        };
        class ENH_NumberSystems: ENH_NumberMarkers
        {
          idc = IDC_STATUSBAR_NUMSYSTEMS;
          x = ORIGIN_X_STATUSBAR - 32 * GRID_W - 2 * SPACE_X;
        };
        class ENH_IconSystems: ENH_IconMarkers
        {
          idc = IDC_STATUSBAR_ICONSYSTEMS;
          x = ORIGIN_X_STATUSBAR - 35 * GRID_W - 2 * SPACE_X;
          text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeModules_ca.paa";
        };
        class ENH_NumberWaypoints: ENH_NumberMarkers
        {
          idc = IDC_STATUSBAR_NUMWAYPOINTS;
          x = ORIGIN_X_STATUSBAR - 42 * GRID_W - 2 * SPACE_X;
        };
        class ENH_IconWaypoints: ENH_IconMarkers
        {
          idc = IDC_STATUSBAR_ICONWAYPOINTS;
          x = ORIGIN_X_STATUSBAR - 45 * GRID_W - 2 * SPACE_X;
          text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeWaypoints_ca.paa";
        };
        class ENH_NumberTriggers: ENH_NumberMarkers
        {
          idc = IDC_STATUSBAR_NUMTRIGGERS;
          x = ORIGIN_X_STATUSBAR - 52 * GRID_W - 2 * SPACE_X;
        };
        class ENH_IconTriggers: ENH_IconMarkers
        {
          idc = IDC_STATUSBAR_ICONTRIGGERS;
          x = ORIGIN_X_STATUSBAR - 55 * GRID_W - 2 * SPACE_X;
          text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeTriggers_ca.paa";
        };
        class ENH_NumberGroups: ENH_NumberMarkers
        {
          idc = IDC_STATUSBAR_NUMGROUPS;
          x = ORIGIN_X_STATUSBAR - 62 * GRID_W - 2 * SPACE_X;
        };
        class ENH_IconGroups: ENH_IconMarkers
        {
          idc = IDC_STATUSBAR_ICONGROUPS;
          x = ORIGIN_X_STATUSBAR - 65 * GRID_W - 2 * SPACE_X;
          text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeGroups_ca.paa";
        };
        class ENH_NumberObjects: ENH_NumberMarkers
        {
          idc = IDC_STATUSBAR_NUMOBJECTS;
          x = ORIGIN_X_STATUSBAR - 72 * GRID_W - 2 * SPACE_X;
        };
        class ENH_IconObjects: ENH_IconMarkers
        {
          idc = IDC_STATUSBAR_ICONOBJECTS;
          x = ORIGIN_X_STATUSBAR - 75 * GRID_W - 2 * SPACE_X;
          text = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeObjects_ca.paa";
        };
        #endif
      };
    };
    class MenuStrip: ctrlMenuStrip
    {
      class Items
      {
        items[] += {"ENH_About"};

        class Interface
        {
          items[] += {"ENH_ToggleMinimap"};
        };
        class ENH_ToggleMinimap
        {
          text = "$STR_ENH_TOGGLEMINIMAP";
          action = "'toggleFromMenu' call ENH_fnc_3DENMinimap";
          shortcuts[] = {INPUT_SHIFT_OFFSET + DIK_M};
        };

        #include "menuStrip_about.hpp"
        #include "menuStrip_tools.hpp"
        #include "menuStrip_help.hpp"
      };
    };
    class PanelRight: ctrlControlsGroupNoScrollbars
    {
      class Controls
      {
        class PanelRightHistory;
        class ENH_PanelRightFavorites: PanelRightHistory
        {
          idc = IDC_DISPLAY3DEN_FAVORITES;
          class Controls
          {
            class ENH_Footer: ctrlStaticFooter
            {
              y = safezoneH - (28 + 13) * GRID_H;
              w = 60 * GRID_W;
              h = 13 * GRID_H;
            };
            class ENH_PanelRightFavorites_Text: ctrlStatic
            {
              text = "$STR_ENH_DISPLAY3DEN_PLACEENTITY";
              y = safezoneH - (28 + 12) * GRID_H;
              w = 60 * GRID_W;
              h = CTRL_DEFAULT_H;
              style = 2;
            };
            class ENH_PanelRightFavorites_Search: ctrlEdit
            {
              idc = 1336;
              x = GRID_W;
              y = GRID_H;
              w = 58 * GRID_W;
              h = CTRL_DEFAULT_H;
            };
            class ENH_PanelRightFavorites_Tree: ctrlTree
            {
              idc = 1338;
              idcSearch = 1336;
              x = 0;
              y = 7 * GRID_H;
              w = 60 * GRID_W;
              h = safezoneH - (28 + 21) * GRID_H;
              borderSize = 0;
              colorBorder[] = {0,0,0,0};
              multiselectEnabled = 1;
            };
            class ENH_PanelRightFavorites_Delete: ctrlButton
            {
              idc = 1339;
              text = "$STR_DISP_DELETE";
              x = GRID_W;
              y = safezoneH - (28 + 6) * GRID_H;
              w = 58 * GRID_W;
              h = CTRL_DEFAULT_H;
            };
          };
        };
        class TabRightSections: ctrlToolbox
        {
          columns = 3;
          strings[] = {"$STR_3DEN_DISPLAY3DEN_ASSETS", "$STR_3DEN_DISPLAY3DEN_HISTORY", "$STR_3DEN_FAVORITE_TEXTPLURAL"};
          values[] = {1039, 1040, IDC_DISPLAY3DEN_FAVORITES};
        };
      };
    };
    class PanelLeft: ctrlControlsGroupNoScrollbars
    {
      class Controls
      {
        class PanelLeftEdit: ctrlControlsGroupNoScrollbars
        {
          class Controls
          {
            class EditPanel: ctrlControlsGroupNoScrollbars
            {
              class Controls
              {
                class Delete;
                class ENH_DeleteEmptyLayers: Delete
                {
                  idc = -1;
                  text = "\3denEnhanced\data\entitylist_deleteEmpty_ca.paa";
                  x = 7 * GRID_W;
                  tooltip = "$STR_ENH_TOOLS_DELETEEMPTYLAYERS";
                  onButtonClick = "call ENH_fnc_deleteEmptyLayers";
                };
                class ENH_SelectLayers: Delete
                {
                  idc = -1;
                  text = "\3denEnhanced\data\selectAllLayers_ca.paa";
                  x = 29 * GRID_W;
                  tooltip = "$STR_ENH_TOOLS_SELECTALLLAYERS";
                  onButtonClick = "set3DENSelected (all3DENEntities # 6)";
                };
              };
            };
          };
        };
        class PanelLeftLocations: ctrlControlsGroupNoScrollbars
        {
          class Controls
          {
            class Locations: ctrlTree
            {
              idc = IDC_DISPLAY3DEN_SEARCH_TREE;
              x = 0;
              y = 7 * GRID_H;
              w = 60 * GRID_W;
              h = safezoneH - 35 * GRID_H;
              onTreeDblClick = "['select',_this] call bis_fnc_3DENListLocations; ['view'] call ENH_fnc_locationList_enhanced";
              disableKeyboardSearch = 1;
              expandOnDoubleclick = 0;
              idcSearch = 800;
            };
            class EditPanel: ctrlControlsGroupNoScrollbars
            {
              y = safezoneH - 29 * GRID_H;
              w = 60 * GRID_W;
              h = 7 * GRID_H;
              class Controls
              {
                class EditPanelBackground: ctrlStatic
                {
                  w = 60 * GRID_W;
                  h = 7 * GRID_H;
                  colorBackground[] = {0.2,0.2,0.2,1};
                };
                class Delete: ctrlButtonToolbar
                {
                  idc = 101;
                  text = "\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\entityList_delete_ca.paa";
                  x = GRID_W;
                  y = GRID_H;
                  w = 5 * GRID_W;
                  h = 5 * GRID_H;
                  tooltip = "$STR_DISP_DELETE";
                  onButtonClick = "['delete'] call ENH_fnc_locationList_enhanced";
                };
                class Add: Delete
                {
                  idc = 102;
                  text = "\3denEnhanced\data\panelLeft_addLocation_ca.paa";
                  x = 54 * GRID_W;
                  tooltip = "$STR_A3_CFGVEHICLES_MODULECURATORADDEDITABLEOBJECTS_ARGUMENTS_ADDCREW_VALUES_YES";
                  onButtonClick = "['add'] spawn ENH_fnc_locationList_enhanced";
                };
              };
            };
          };
        };
      };
    };
  };
};