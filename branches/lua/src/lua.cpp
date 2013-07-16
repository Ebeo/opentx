/*
 * Authors (alphabetical order)
 * - Andre Bernet <bernet.andre@gmail.com>
 * - Andreas Weitl
 * - Bertrand Songis <bsongis@gmail.com>
 * - Bryan J. Rentoul (Gruvin) <gruvin@gmail.com>
 * - Cameron Weeks <th9xer@gmail.com>
 * - Erez Raviv
 * - Gabriel Birkus
 * - Jean-Pierre Parisy
 * - Karl Szmutny
 * - Michael Blandford
 * - Michal Hlavinka
 * - Pat Mackenzie
 * - Philip Moss
 * - Rob Thomson
 * - Romolo Manfredini <romolo.manfredini@gmail.com>
 * - Thomas Husterer
 *
 * opentx is based on code named
 * gruvin9x by Bryan J. Rentoul: http://code.google.com/p/gruvin9x/,
 * er9x by Erez Raviv: http://code.google.com/p/er9x/,
 * and the original (and ongoing) project by
 * Thomas Husterer, th9x: http://code.google.com/p/th9x/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include "opentx.h"

#if !defined(SIMU)
extern "C" {
#endif
  #include <lua.h>
  #include <lauxlib.h>
  #include <lualib.h>
#if !defined(SIMU)
}
#endif

bool luaReload = true;
ScriptInternalData scriptInternalData[MAX_SCRIPTS];
lua_State *L = NULL;

static int countdown = 10;
void hook(lua_State* L, lua_Debug *ar)
{
  if (countdown > 0) {
    TRACE("Countdown hook(%d)", countdown);
    --countdown;
  }
  else {
    // From now on, as soon as a line is executed, error
    // keep erroring until you're script reaches the top
    lua_sethook(L, hook, LUA_MASKLINE, 0);
    luaL_error(L, "");
  }
}

int luaGetInputs(uint8_t idx)
{
  ScriptData & sd = g_model.scriptsData[idx];
  ScriptInternalData & sid = scriptInternalData[idx];

  char functionName[sizeof(sd.file)+8];
  strncpy(functionName, sd.file, sizeof(sd.file));
  functionName[sizeof(sd.file)] = '\0';
  strcat(functionName, "Inputs");

  lua_getglobal(L, functionName);  /* function to be called */

  /* do the call (0 arguments, 1 result) */
  int status = lua_pcall(L, 0, 1, 0);
  if (status != 0) {
    return status;
  }

  luaL_checktype(L, -1, LUA_TTABLE);

  sid.inputsCount = 0;
  for (lua_pushnil(L); lua_next(L, -2) && sid.inputsCount<MAX_SCRIPT_OUTPUTS; lua_pop(L, 1)) {
    luaL_checktype(L, -2, LUA_TNUMBER); // key is number
    luaL_checktype(L, -1, LUA_TTABLE); // value is table
    uint8_t field = 0;
    for (lua_pushnil(L); lua_next(L, -2) && field<5; lua_pop(L, 1), field++) {
      switch (field) {
        case 0:
          luaL_checktype(L, -2, LUA_TNUMBER); // key is number
          luaL_checktype(L, -1, LUA_TSTRING); // value is string
          sid.inputs[sid.inputsCount].name = lua_tostring(L, -1);
          break;
        case 1:
          luaL_checktype(L, -2, LUA_TNUMBER); // key is number
          luaL_checktype(L, -1, LUA_TNUMBER); // value is number
          sid.inputs[sid.inputsCount].type = lua_tointeger(L, -1);
          if (sid.inputs[sid.inputsCount].type == 0) {
            sid.inputs[sid.inputsCount].min = -100;
            sid.inputs[sid.inputsCount].max = 100;
          }
          else {
            sid.inputs[sid.inputsCount].max = MIXSRC_LAST_TELEM;
          }
          break;
        case 2:
          luaL_checktype(L, -2, LUA_TNUMBER); // key is number
          luaL_checktype(L, -1, LUA_TNUMBER); // value is number
          sid.inputs[sid.inputsCount].min = lua_tointeger(L, -1);
          break;
        case 3:
          luaL_checktype(L, -2, LUA_TNUMBER); // key is number
          luaL_checktype(L, -1, LUA_TNUMBER); // value is number
          sid.inputs[sid.inputsCount].max = lua_tointeger(L, -1);
          break;
        case 4:
          luaL_checktype(L, -2, LUA_TNUMBER); // key is number
          luaL_checktype(L, -1, LUA_TNUMBER); // value is number
          sid.inputs[sid.inputsCount].def = lua_tointeger(L, -1);
          break;
      }
    }

    sid.inputsCount++;
  }

  return LUA_OK;
}

int luaGetOutputs(uint8_t idx)
{
  ScriptData & sd = g_model.scriptsData[idx];
  ScriptInternalData & sid = scriptInternalData[idx];

  char functionName[sizeof(sd.file)+8];
  strncpy(functionName, sd.file, sizeof(sd.file));
  functionName[sizeof(sd.file)] = '\0';
  strcat(functionName, "Outputs");

  lua_getglobal(L, functionName);  /* function to be called */

  /* do the call (0 arguments, 1 result) */
  int status = lua_pcall(L, 0, 1, 0);
  if (status != 0) {
    return status;
  }

  luaL_checktype(L, -1, LUA_TTABLE);

  sid.outputsCount = 0;
  for (lua_pushnil(L); lua_next(L, -2) && sid.outputsCount<MAX_SCRIPT_OUTPUTS; lua_pop(L, 1)) {
    luaL_checktype(L, -2, LUA_TNUMBER); // key is number
    luaL_checktype(L, -1, LUA_TSTRING); // value is string
    sid.outputs[sid.outputsCount++].name = lua_tostring(L, -1);
  }

  return LUA_OK;
}

void luaLoadModelScripts()
{
  memset(scriptInternalData, 0, sizeof(scriptInternalData));

  if (L) {
    lua_close(L);
    L = NULL;
  }

  L = luaL_newstate();

  // Init lua
  luaL_openlibs(L);
  lua_sethook(L, hook, LUA_MASKCOUNT, 100);

  // Load scripts
  for (int i=0; i<MAX_SCRIPTS; i++) {
    ScriptData & sd = g_model.scriptsData[i];
    ScriptInternalData & sid = scriptInternalData[i];
    sid.state = SCRIPT_NOFILE;
    if (ZEXIST(sd.file)) {
      char filename[sizeof(SCRIPTS_PATH)+sizeof(sd.file)+sizeof(SCRIPTS_EXT)] = SCRIPTS_PATH "/";
      strncpy(filename+sizeof(SCRIPTS_PATH), sd.file, sizeof(sd.file));
      filename[sizeof(SCRIPTS_PATH)+sizeof(sd.file)] = '\0';
      strcat(filename+sizeof(SCRIPTS_PATH), SCRIPTS_EXT);
      if (luaL_loadfile(L, filename) == LUA_OK &&
          lua_pcall(L, 0, LUA_MULTRET, 0) == LUA_OK &&
          luaGetInputs(i) == LUA_OK &&
          luaGetOutputs(i) == LUA_OK) {
        sid.state = SCRIPT_OK;
        strncpy(sid.function, sd.file, sizeof(sd.file));
        sid.function[sizeof(sd.file)] = '\0';
        strcat(sid.function, "Run");
      }
      else {
        TRACE("Error in script %s: %s", filename, lua_tostring(L, -1));
        sid.state = SCRIPT_SYNTAX_ERROR;
      }
    }
  }
}

void luaTask(void * pdata)
{
  while (1) {
    if (luaReload) {
      luaReload = false;
      luaLoadModelScripts();
    }

    for (int i=0; i<MAX_SCRIPTS; i++) {
      ScriptData & sd = g_model.scriptsData[i];
      ScriptInternalData & sid = scriptInternalData[i];
      if (sid.state == SCRIPT_OK) {
        countdown = 10;
        lua_sethook(L, hook, LUA_MASKCOUNT, 100);
        lua_getglobal(L, sid.function);  /* function to be called */
        for (int j=0; j<sid.inputsCount; j++) {
          int8_t input = sd.inputs[j];
          if (sid.inputs[j].type == 0 || input==0)
            lua_pushnumber(L, input);
          else
            lua_pushnumber(L, getValue(input-1));
        }
        /* do the call (2 arguments, 1 result) */
        if (lua_pcall(L, sid.inputsCount, sid.outputsCount, 0) == 0) {
          for (int j=0; j<sid.outputsCount; j++) {
            /* retrieve result */
            if (!lua_isnumber(L, -1)) {
              sid.state = (countdown==0 ? SCRIPT_KILLED : SCRIPT_SYNTAX_ERROR);
              TRACE("Script %10s disabled", sd.file);
              break;
            }
            sid.outputs[j].value = lua_tointeger(L, -1);
            lua_pop(L, 1);  /* pop returned value */
          }
        }
        else {
          sid.state = (countdown==0 ? SCRIPT_KILLED : SCRIPT_SYNTAX_ERROR);
          TRACE("Script %10s disabled", sd.file);
        }
      }
    }
    CoTickDelay(5);  // 10ms for now
  }
}
