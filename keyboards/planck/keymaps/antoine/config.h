// Copyright 2024 Antoine
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define XXX KC_NO

// Layout wrapper for Planck (4x12 ortholinear = 48 keys)
// Maps the fortitude60-style 5x6+5 layout to Planck's 4x12 grid
#define LAYOUT_antoine(\
K00, K01, K02, K03, K04, K05,                K06, K07, K08, K09, K010, K011,\
K10, K11, K12, K13, K14, K15,                K16, K17, K18, K19, K110, K111,\
K20, K21, K22, K23, K24, K25,                K26, K27, K28, K29, K210, K211,\
K30, K31, K32, K33, K34, K35, K351,    K352, K36, K37, K38, K39, K310, K311,\
          K40, K41 , K42, K43, K44,      K45, K46, K47, K48, K49\
)\
LAYOUT_planck_grid(\
K10, K11, K12, K13, K14, K15,                K16, K17, K18, K19, K110, K111,\
K20, K21, K22, K23, K24, K25,                K26, K27, K28, K29, K210, K211,\
K30, K31, K32, K33, K34, K35,                K36, K37, K38, K39, K310, K311,\
K40, K41, K42, K43, K44, K351,               K352, K45, K46, K47, K48, K49\
)
