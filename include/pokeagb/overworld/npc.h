/*
 * This file is part of PokeAGB.
 *
 * PokeAGB is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PokeAGB is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PokeAGB.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef POKEAGB_OVERWORLD_NPC_H_
#define POKEAGB_OVERWORLD_NPC_H_

#include <pokeagb/types.h>
#include <pokeagb/macros.h>
#include <pokeagb/graphics/sprites.h>

#ifdef __cplusplus
extern "C" {
#endif

  /** An NPC in the overworld
   */
  struct npc_state {
    u8 bitfield;
    u8 field1;
    u8 field2;
    u8 field3;
    u8 oam_id;
    u8 type_id;
    u8 running_behavior;
    u8 is_trainer;
    u8 local_id;
    u8 local_map_number;
    u8 local_map_bank;
    u8 height;
    struct coords16 stay_around;
    struct coords16 to;
    struct coords16 from;
    u8 direction;
    u8 movement_area;
    u8 field1A;
    u8 oamid2;
    u8 state;
    u8 sight_distance;
    u8 tile_to;
    u8 tile_from;
    u8 field20;
    u8 field21;
    u8 field22;
    u8 field23;
  };

  /** The player's movement state
   */
  struct walkrun {
    u8 bitfield;
    u8 bike;
    u8 running2;
    u8 running1;
    u8 oamid;
    u8 npcid;
    u8 lock;
    u8 gender;
    u8 xmode;
    u8 field9;
    u8 fieldA;
    u8 fieldB;
    u32 fieldC;
    u32 field10;
    u32 field14;
    u8 field18;
    u8 field19;
    u16 field1A;
    u16 most_recent_override_tile;
  };

  /** An NPC in the ROM
   */
  struct rom_npc {
    u8 nr;
    u8 type_nr;
    u8 rival;
    u8 field3;
    u16 x;
    u16 y;
    u8 height;
    u8 behaviour;
    u8 movement_area;
    u8 fieldB;
    u8 trainer_or_mapnumber;
    u8 fieldD;
    u8 sight_distance_or_mapbank;
    u8 *script;
    u16 local_id;
    u16 field16;
  };

  /** The player's movement state
   */
  extern struct walkrun walkrun_state;

  /** Currently loaded NPCs
   */
  extern struct npc_state npc_states[16];

  LONG_CALL u8 npc_half_reset_no_checks(struct npc_state*);
  LONG_CALL void npc_half_reset(struct npc_state *);
  LONG_CALL int npc_set_state_2(struct npc_state *, u8);
  LONG_CALL u8 npc_half_reset_when_bit7_is_set(struct npc_state *);
  LONG_CALL struct rom_npc *rom_npc_by_local_id_and_map(u8, u8, u8);
  LONG_CALL u8 npc_instanciation_something(struct rom_npc*, u8, u8, u16, u16);
  LONG_CALL void npc_change_sprite(struct npc_state*, u8);
  LONG_CALL void npc_turn(struct npc_state*, u8);

#ifdef __cplusplus
}
#endif

#endif /* POKEAGB_OVERWORLD_NPC_H_ */