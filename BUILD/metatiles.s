;
; File generated by cc65 v 2.18 - Git c0a873e
;
	.fopt		compiler,"cc65 v 2.18 - Git c0a873e"
	.setcpu		"6502"
	.smart		on
	.autoimport	on
	.case		on
	.debuginfo	off
	.importzp	sp, sreg, regsave, regbank
	.importzp	tmp1, tmp2, tmp3, tmp4, ptr1, ptr2, ptr3, ptr4
	.macpack	longbranch
	.forceimport	__STARTUP__
	.import		_pal_bg
	.import		_pal_spr
	.import		_ppu_wait_nmi
	.import		_ppu_off
	.import		_ppu_on_all
	.import		_oam_clear
	.import		_oam_meta_spr
	.import		_pad_poll
	.import		_bank_spr
	.import		_set_vram_update
	.import		_memcpy
	.import		_set_vram_buffer
	.import		_set_scroll_y
	.import		_get_ppu_addr
	.import		_set_data_pointer
	.import		_set_mt_pointer
	.import		_buffer_1_mt
	.import		_buffer_4_mt
	.import		_flush_vram_update2
	.export		_RoundSprL
	.export		_RoundSprR
	.export		_pad1
	.export		_collision
	.export		_collision_L
	.export		_collision_R
	.export		_collision_U
	.export		_collision_D
	.export		_coordinates
	.export		_temp1
	.export		_temp2
	.export		_temp3
	.export		_temp4
	.export		_temp5
	.export		_temp6
	.export		_eject_L
	.export		_eject_R
	.export		_eject_D
	.export		_eject_U
	.export		_direction
	.export		_address
	.export		_x
	.export		_y
	.export		_index
	.export		_map
	.export		_scroll_x
	.export		_scroll_y
	.export		_hero_velocity_x
	.export		_hero_velocity_y
	.export		_old_x
	.export		_old_y
	.export		_temp_x
	.export		_temp_y
	.export		_c_map
	.export		_c_map2
	.export		_Generic
	.export		_BoxGuy1
	.export		_palette_bg
	.export		_palette_sp
	.export		_metatiles1
	.export		_Room1
	.export		_load_room
	.export		_draw_sprites
	.export		_movement
	.export		_bg_collision_sub
	.export		_bg_coll_L
	.export		_bg_coll_R
	.export		_bg_coll_U
	.export		_bg_coll_D
	.export		_main

.segment	"DATA"

_BoxGuy1:
	.word	$4000
	.word	$3000

.segment	"RODATA"

_RoundSprL:
	.byte	$FF
	.byte	$FF
	.byte	$02
	.byte	$00
	.byte	$07
	.byte	$FF
	.byte	$03
	.byte	$00
	.byte	$FF
	.byte	$07
	.byte	$12
	.byte	$00
	.byte	$07
	.byte	$07
	.byte	$13
	.byte	$00
	.byte	$80
_RoundSprR:
	.byte	$FF
	.byte	$FF
	.byte	$00
	.byte	$00
	.byte	$07
	.byte	$FF
	.byte	$01
	.byte	$00
	.byte	$FF
	.byte	$07
	.byte	$10
	.byte	$00
	.byte	$07
	.byte	$07
	.byte	$11
	.byte	$00
	.byte	$80
_palette_bg:
	.byte	$0F
	.byte	$00
	.byte	$10
	.byte	$30
	.byte	$0F
	.byte	$07
	.byte	$17
	.byte	$27
	.byte	$0F
	.byte	$02
	.byte	$12
	.byte	$22
	.byte	$0F
	.byte	$09
	.byte	$19
	.byte	$29
_palette_sp:
	.byte	$0F
	.byte	$07
	.byte	$28
	.byte	$38
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
_metatiles1:
	.byte	$02
	.byte	$02
	.byte	$02
	.byte	$02
	.byte	$03
	.byte	$04
	.byte	$04
	.byte	$04
	.byte	$04
	.byte	$01
	.byte	$09
	.byte	$09
	.byte	$09
	.byte	$09
	.byte	$02
	.byte	$05
	.byte	$06
	.byte	$08
	.byte	$07
	.byte	$01
	.byte	$05
	.byte	$06
	.byte	$08
	.byte	$07
	.byte	$00
	.byte	$21
	.byte	$21
	.byte	$21
	.byte	$21
	.byte	$00
	.byte	$30
	.byte	$30
	.byte	$30
	.byte	$30
	.byte	$00
	.byte	$31
	.byte	$31
	.byte	$31
	.byte	$31
	.byte	$00
	.byte	$32
	.byte	$32
	.byte	$32
	.byte	$32
	.byte	$00
	.byte	$33
	.byte	$33
	.byte	$33
	.byte	$33
	.byte	$00
	.byte	$34
	.byte	$34
	.byte	$34
	.byte	$34
	.byte	$00
	.byte	$35
	.byte	$35
	.byte	$35
	.byte	$35
	.byte	$00
	.byte	$36
	.byte	$36
	.byte	$36
	.byte	$36
	.byte	$00
	.byte	$37
	.byte	$37
	.byte	$37
	.byte	$37
	.byte	$00
	.byte	$38
	.byte	$38
	.byte	$38
	.byte	$38
	.byte	$00
	.byte	$39
	.byte	$39
	.byte	$39
	.byte	$39
	.byte	$00
	.byte	$41
	.byte	$41
	.byte	$41
	.byte	$41
	.byte	$00
	.byte	$42
	.byte	$42
	.byte	$42
	.byte	$42
	.byte	$00
	.byte	$43
	.byte	$43
	.byte	$43
	.byte	$43
	.byte	$00
	.byte	$44
	.byte	$44
	.byte	$44
	.byte	$44
	.byte	$00
	.byte	$45
	.byte	$45
	.byte	$45
	.byte	$45
	.byte	$00
	.byte	$46
	.byte	$46
	.byte	$46
	.byte	$46
	.byte	$00
	.byte	$47
	.byte	$47
	.byte	$47
	.byte	$47
	.byte	$00
	.byte	$48
	.byte	$48
	.byte	$48
	.byte	$48
	.byte	$00
	.byte	$49
	.byte	$49
	.byte	$49
	.byte	$49
	.byte	$00
	.byte	$4A
	.byte	$4A
	.byte	$4A
	.byte	$4A
	.byte	$00
	.byte	$4B
	.byte	$4B
	.byte	$4B
	.byte	$4B
	.byte	$00
	.byte	$4C
	.byte	$4C
	.byte	$4C
	.byte	$4C
	.byte	$00
	.byte	$4D
	.byte	$4D
	.byte	$4D
	.byte	$4D
	.byte	$00
	.byte	$4E
	.byte	$4E
	.byte	$4E
	.byte	$4E
	.byte	$00
	.byte	$4F
	.byte	$4F
	.byte	$4F
	.byte	$4F
	.byte	$00
	.byte	$50
	.byte	$50
	.byte	$50
	.byte	$50
	.byte	$00
	.byte	$51
	.byte	$51
	.byte	$51
	.byte	$51
	.byte	$00
	.byte	$52
	.byte	$52
	.byte	$52
	.byte	$52
	.byte	$00
	.byte	$53
	.byte	$53
	.byte	$53
	.byte	$53
	.byte	$00
	.byte	$54
	.byte	$54
	.byte	$54
	.byte	$54
	.byte	$00
	.byte	$55
	.byte	$55
	.byte	$55
	.byte	$55
	.byte	$00
	.byte	$56
	.byte	$56
	.byte	$56
	.byte	$56
	.byte	$00
	.byte	$57
	.byte	$57
	.byte	$57
	.byte	$57
	.byte	$00
	.byte	$58
	.byte	$58
	.byte	$58
	.byte	$58
	.byte	$00
	.byte	$59
	.byte	$59
	.byte	$59
	.byte	$59
	.byte	$00
	.byte	$5A
	.byte	$5A
	.byte	$5A
	.byte	$5A
	.byte	$00
	.byte	$30
	.byte	$30
	.byte	$30
	.byte	$30
	.byte	$00
	.byte	$31
	.byte	$31
	.byte	$31
	.byte	$31
	.byte	$00
	.byte	$32
	.byte	$32
	.byte	$32
	.byte	$32
	.byte	$00
	.byte	$33
	.byte	$33
	.byte	$33
	.byte	$33
	.byte	$00
	.byte	$34
	.byte	$34
	.byte	$34
	.byte	$34
	.byte	$00
	.byte	$35
	.byte	$35
	.byte	$35
	.byte	$35
	.byte	$00
	.byte	$41
	.byte	$41
	.byte	$41
	.byte	$41
	.byte	$01
	.byte	$42
	.byte	$42
	.byte	$42
	.byte	$42
	.byte	$01
	.byte	$43
	.byte	$43
	.byte	$43
	.byte	$43
	.byte	$01
	.byte	$44
	.byte	$44
	.byte	$44
	.byte	$44
	.byte	$01
	.byte	$45
	.byte	$45
	.byte	$45
	.byte	$45
	.byte	$01
	.byte	$46
	.byte	$46
	.byte	$46
	.byte	$46
	.byte	$01
	.byte	$47
	.byte	$47
	.byte	$47
	.byte	$47
	.byte	$01
	.byte	$48
	.byte	$48
	.byte	$48
	.byte	$48
	.byte	$01
	.byte	$49
	.byte	$49
	.byte	$49
	.byte	$49
	.byte	$01
	.byte	$4A
	.byte	$4A
	.byte	$4A
	.byte	$4A
	.byte	$01
	.byte	$4B
	.byte	$4B
	.byte	$4B
	.byte	$4B
	.byte	$01
	.byte	$4C
	.byte	$4C
	.byte	$4C
	.byte	$4C
	.byte	$01
	.byte	$4D
	.byte	$4D
	.byte	$4D
	.byte	$4D
	.byte	$01
	.byte	$4E
	.byte	$4E
	.byte	$4E
	.byte	$4E
	.byte	$01
	.byte	$4F
	.byte	$4F
	.byte	$4F
	.byte	$4F
	.byte	$01
	.byte	$50
	.byte	$50
	.byte	$50
	.byte	$50
	.byte	$01
	.byte	$51
	.byte	$51
	.byte	$51
	.byte	$51
	.byte	$01
	.byte	$52
	.byte	$52
	.byte	$52
	.byte	$52
	.byte	$01
	.byte	$53
	.byte	$53
	.byte	$53
	.byte	$53
	.byte	$01
	.byte	$54
	.byte	$54
	.byte	$54
	.byte	$54
	.byte	$01
	.byte	$55
	.byte	$55
	.byte	$55
	.byte	$55
	.byte	$01
	.byte	$56
	.byte	$56
	.byte	$56
	.byte	$56
	.byte	$01
	.byte	$57
	.byte	$57
	.byte	$57
	.byte	$57
	.byte	$01
	.byte	$58
	.byte	$58
	.byte	$58
	.byte	$58
	.byte	$01
	.byte	$59
	.byte	$59
	.byte	$59
	.byte	$59
	.byte	$01
	.byte	$5A
	.byte	$5A
	.byte	$5A
	.byte	$5A
	.byte	$01
	.byte	$30
	.byte	$30
	.byte	$30
	.byte	$30
	.byte	$01
	.byte	$31
	.byte	$31
	.byte	$31
	.byte	$31
	.byte	$01
	.byte	$32
	.byte	$32
	.byte	$32
	.byte	$32
	.byte	$01
	.byte	$33
	.byte	$33
	.byte	$33
	.byte	$33
	.byte	$01
	.byte	$34
	.byte	$34
	.byte	$34
	.byte	$34
	.byte	$01
	.byte	$35
	.byte	$35
	.byte	$35
	.byte	$35
	.byte	$01
	.byte	$41
	.byte	$41
	.byte	$41
	.byte	$41
	.byte	$02
	.byte	$42
	.byte	$42
	.byte	$42
	.byte	$42
	.byte	$02
	.byte	$43
	.byte	$43
	.byte	$43
	.byte	$43
	.byte	$02
	.byte	$44
	.byte	$44
	.byte	$44
	.byte	$44
	.byte	$02
	.byte	$45
	.byte	$45
	.byte	$45
	.byte	$45
	.byte	$02
	.byte	$46
	.byte	$46
	.byte	$46
	.byte	$46
	.byte	$02
	.byte	$47
	.byte	$47
	.byte	$47
	.byte	$47
	.byte	$02
	.byte	$48
	.byte	$48
	.byte	$48
	.byte	$48
	.byte	$02
	.byte	$49
	.byte	$49
	.byte	$49
	.byte	$49
	.byte	$02
	.byte	$4A
	.byte	$4A
	.byte	$4A
	.byte	$4A
	.byte	$02
	.byte	$4B
	.byte	$4B
	.byte	$4B
	.byte	$4B
	.byte	$02
	.byte	$4C
	.byte	$4C
	.byte	$4C
	.byte	$4C
	.byte	$02
	.byte	$4D
	.byte	$4D
	.byte	$4D
	.byte	$4D
	.byte	$02
	.byte	$4E
	.byte	$4E
	.byte	$4E
	.byte	$4E
	.byte	$02
	.byte	$4F
	.byte	$4F
	.byte	$4F
	.byte	$4F
	.byte	$02
	.byte	$50
	.byte	$50
	.byte	$50
	.byte	$50
	.byte	$02
	.byte	$51
	.byte	$51
	.byte	$51
	.byte	$51
	.byte	$02
	.byte	$52
	.byte	$52
	.byte	$52
	.byte	$52
	.byte	$02
	.byte	$53
	.byte	$53
	.byte	$53
	.byte	$53
	.byte	$02
	.byte	$54
	.byte	$54
	.byte	$54
	.byte	$54
	.byte	$02
	.byte	$55
	.byte	$55
	.byte	$55
	.byte	$55
	.byte	$02
	.byte	$56
	.byte	$56
	.byte	$56
	.byte	$56
	.byte	$02
	.byte	$57
	.byte	$57
	.byte	$57
	.byte	$57
	.byte	$02
	.byte	$58
	.byte	$58
	.byte	$58
	.byte	$58
	.byte	$02
	.byte	$59
	.byte	$59
	.byte	$59
	.byte	$59
	.byte	$02
	.byte	$5A
	.byte	$5A
	.byte	$5A
	.byte	$5A
	.byte	$02
	.byte	$30
	.byte	$30
	.byte	$30
	.byte	$30
	.byte	$02
	.byte	$31
	.byte	$31
	.byte	$31
	.byte	$31
	.byte	$02
	.byte	$32
	.byte	$32
	.byte	$32
	.byte	$32
	.byte	$02
	.byte	$33
	.byte	$33
	.byte	$33
	.byte	$33
	.byte	$02
	.byte	$34
	.byte	$34
	.byte	$34
	.byte	$34
	.byte	$02
	.byte	$35
	.byte	$35
	.byte	$35
	.byte	$35
	.byte	$02
	.byte	$41
	.byte	$41
	.byte	$41
	.byte	$41
	.byte	$03
	.byte	$42
	.byte	$42
	.byte	$42
	.byte	$42
	.byte	$03
	.byte	$43
	.byte	$43
	.byte	$43
	.byte	$43
	.byte	$03
	.byte	$44
	.byte	$44
	.byte	$44
	.byte	$44
	.byte	$03
	.byte	$45
	.byte	$45
	.byte	$45
	.byte	$45
	.byte	$03
	.byte	$46
	.byte	$46
	.byte	$46
	.byte	$46
	.byte	$03
	.byte	$47
	.byte	$47
	.byte	$47
	.byte	$47
	.byte	$03
	.byte	$48
	.byte	$48
	.byte	$48
	.byte	$48
	.byte	$03
	.byte	$49
	.byte	$49
	.byte	$49
	.byte	$49
	.byte	$03
	.byte	$4A
	.byte	$4A
	.byte	$4A
	.byte	$4A
	.byte	$03
	.byte	$4B
	.byte	$4B
	.byte	$4B
	.byte	$4B
	.byte	$03
	.byte	$4C
	.byte	$4C
	.byte	$4C
	.byte	$4C
	.byte	$03
	.byte	$4D
	.byte	$4D
	.byte	$4D
	.byte	$4D
	.byte	$03
	.byte	$4E
	.byte	$4E
	.byte	$4E
	.byte	$4E
	.byte	$03
	.byte	$4F
	.byte	$4F
	.byte	$4F
	.byte	$4F
	.byte	$03
	.byte	$50
	.byte	$50
	.byte	$50
	.byte	$50
	.byte	$03
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$52
	.byte	$52
	.byte	$52
	.byte	$52
	.byte	$03
	.byte	$53
	.byte	$53
	.byte	$53
	.byte	$53
	.byte	$03
	.byte	$54
	.byte	$54
	.byte	$54
	.byte	$54
	.byte	$03
	.byte	$55
	.byte	$55
	.byte	$55
	.byte	$55
	.byte	$03
	.byte	$56
	.byte	$56
	.byte	$56
	.byte	$56
	.byte	$03
	.byte	$57
	.byte	$57
	.byte	$57
	.byte	$57
	.byte	$03
	.byte	$58
	.byte	$58
	.byte	$58
	.byte	$58
	.byte	$03
	.byte	$59
	.byte	$59
	.byte	$59
	.byte	$59
	.byte	$03
	.byte	$5A
	.byte	$5A
	.byte	$5A
	.byte	$5A
	.byte	$03
	.byte	$30
	.byte	$30
	.byte	$30
	.byte	$30
	.byte	$03
	.byte	$31
	.byte	$31
	.byte	$31
	.byte	$31
	.byte	$03
	.byte	$32
	.byte	$32
	.byte	$32
	.byte	$32
	.byte	$03
	.byte	$33
	.byte	$33
	.byte	$33
	.byte	$33
	.byte	$03
	.byte	$34
	.byte	$34
	.byte	$34
	.byte	$34
	.byte	$03
	.byte	$35
	.byte	$35
	.byte	$35
	.byte	$35
	.byte	$03
	.byte	$41
	.byte	$41
	.byte	$41
	.byte	$41
	.byte	$00
	.byte	$42
	.byte	$42
	.byte	$42
	.byte	$42
	.byte	$00
	.byte	$43
	.byte	$43
	.byte	$43
	.byte	$43
	.byte	$00
	.byte	$44
	.byte	$44
	.byte	$44
	.byte	$44
	.byte	$00
	.byte	$45
	.byte	$45
	.byte	$45
	.byte	$45
	.byte	$00
	.byte	$46
	.byte	$46
	.byte	$46
	.byte	$46
	.byte	$00
	.byte	$47
	.byte	$47
	.byte	$47
	.byte	$47
	.byte	$00
	.byte	$48
	.byte	$48
	.byte	$48
	.byte	$48
	.byte	$00
	.byte	$49
	.byte	$49
	.byte	$49
	.byte	$49
	.byte	$00
	.byte	$4A
	.byte	$4A
	.byte	$4A
	.byte	$4A
	.byte	$00
	.byte	$4B
	.byte	$4B
	.byte	$4B
	.byte	$4B
	.byte	$00
	.byte	$4C
	.byte	$4C
	.byte	$4C
	.byte	$4C
	.byte	$00
	.byte	$4D
	.byte	$4D
	.byte	$4D
	.byte	$4D
	.byte	$00
	.byte	$4E
	.byte	$4E
	.byte	$4E
	.byte	$4E
	.byte	$00
	.byte	$4F
	.byte	$4F
	.byte	$4F
	.byte	$4F
	.byte	$00
	.byte	$50
	.byte	$50
	.byte	$50
	.byte	$50
	.byte	$00
	.byte	$51
	.byte	$51
	.byte	$51
	.byte	$51
	.byte	$00
	.byte	$52
	.byte	$52
	.byte	$52
	.byte	$52
	.byte	$00
	.byte	$53
	.byte	$53
	.byte	$53
	.byte	$53
	.byte	$00
	.byte	$54
	.byte	$54
	.byte	$54
	.byte	$54
	.byte	$00
	.byte	$55
	.byte	$55
	.byte	$55
	.byte	$55
	.byte	$00
	.byte	$56
	.byte	$56
	.byte	$56
	.byte	$56
	.byte	$00
	.byte	$57
	.byte	$57
	.byte	$57
	.byte	$57
	.byte	$00
	.byte	$58
	.byte	$58
	.byte	$58
	.byte	$58
	.byte	$00
	.byte	$59
	.byte	$59
	.byte	$59
	.byte	$59
	.byte	$00
	.byte	$5A
	.byte	$5A
	.byte	$5A
	.byte	$5A
	.byte	$00
	.byte	$30
	.byte	$30
	.byte	$30
	.byte	$30
	.byte	$00
	.byte	$31
	.byte	$31
	.byte	$31
	.byte	$31
	.byte	$00
	.byte	$32
	.byte	$32
	.byte	$32
	.byte	$32
	.byte	$00
	.byte	$33
	.byte	$33
	.byte	$33
	.byte	$33
	.byte	$00
	.byte	$34
	.byte	$34
	.byte	$34
	.byte	$34
	.byte	$00
	.byte	$35
	.byte	$35
	.byte	$35
	.byte	$35
	.byte	$00
	.byte	$41
	.byte	$41
	.byte	$41
	.byte	$41
	.byte	$01
	.byte	$42
	.byte	$42
	.byte	$42
	.byte	$42
	.byte	$01
	.byte	$43
	.byte	$43
	.byte	$43
	.byte	$43
	.byte	$01
	.byte	$44
	.byte	$44
	.byte	$44
	.byte	$44
	.byte	$01
	.byte	$45
	.byte	$45
	.byte	$45
	.byte	$45
	.byte	$01
	.byte	$46
	.byte	$46
	.byte	$46
	.byte	$46
	.byte	$01
	.byte	$47
	.byte	$47
	.byte	$47
	.byte	$47
	.byte	$01
	.byte	$48
	.byte	$48
	.byte	$48
	.byte	$48
	.byte	$01
	.byte	$49
	.byte	$49
	.byte	$49
	.byte	$49
	.byte	$01
	.byte	$4A
	.byte	$4A
	.byte	$4A
	.byte	$4A
	.byte	$01
	.byte	$4B
	.byte	$4B
	.byte	$4B
	.byte	$4B
	.byte	$01
	.byte	$4C
	.byte	$4C
	.byte	$4C
	.byte	$4C
	.byte	$01
	.byte	$4D
	.byte	$4D
	.byte	$4D
	.byte	$4D
	.byte	$01
	.byte	$4E
	.byte	$4E
	.byte	$4E
	.byte	$4E
	.byte	$01
	.byte	$4F
	.byte	$4F
	.byte	$4F
	.byte	$4F
	.byte	$01
	.byte	$50
	.byte	$50
	.byte	$50
	.byte	$50
	.byte	$01
	.byte	$51
	.byte	$51
	.byte	$51
	.byte	$51
	.byte	$01
	.byte	$52
	.byte	$52
	.byte	$52
	.byte	$52
	.byte	$01
	.byte	$53
	.byte	$53
	.byte	$53
	.byte	$53
	.byte	$01
	.byte	$54
	.byte	$54
	.byte	$54
	.byte	$54
	.byte	$01
	.byte	$55
	.byte	$55
	.byte	$55
	.byte	$55
	.byte	$01
	.byte	$56
	.byte	$56
	.byte	$56
	.byte	$56
	.byte	$01
	.byte	$57
	.byte	$57
	.byte	$57
	.byte	$57
	.byte	$01
	.byte	$58
	.byte	$58
	.byte	$58
	.byte	$58
	.byte	$01
	.byte	$59
	.byte	$59
	.byte	$59
	.byte	$59
	.byte	$01
	.byte	$5A
	.byte	$5A
	.byte	$5A
	.byte	$5A
	.byte	$01
	.byte	$30
	.byte	$30
	.byte	$30
	.byte	$30
	.byte	$01
	.byte	$31
	.byte	$31
	.byte	$31
	.byte	$31
	.byte	$01
	.byte	$32
	.byte	$32
	.byte	$32
	.byte	$32
	.byte	$01
	.byte	$33
	.byte	$33
	.byte	$33
	.byte	$33
	.byte	$01
	.byte	$34
	.byte	$34
	.byte	$34
	.byte	$34
	.byte	$01
	.byte	$35
	.byte	$35
	.byte	$35
	.byte	$35
	.byte	$01
	.byte	$41
	.byte	$41
	.byte	$41
	.byte	$41
	.byte	$02
	.byte	$42
	.byte	$42
	.byte	$42
	.byte	$42
	.byte	$02
	.byte	$43
	.byte	$43
	.byte	$43
	.byte	$43
	.byte	$02
	.byte	$44
	.byte	$44
	.byte	$44
	.byte	$44
	.byte	$02
	.byte	$45
	.byte	$45
	.byte	$45
	.byte	$45
	.byte	$02
	.byte	$46
	.byte	$46
	.byte	$46
	.byte	$46
	.byte	$02
	.byte	$47
	.byte	$47
	.byte	$47
	.byte	$47
	.byte	$02
	.byte	$48
	.byte	$48
	.byte	$48
	.byte	$48
	.byte	$02
	.byte	$49
	.byte	$49
	.byte	$49
	.byte	$49
	.byte	$02
	.byte	$4A
	.byte	$4A
	.byte	$4A
	.byte	$4A
	.byte	$02
	.byte	$4B
	.byte	$4B
	.byte	$4B
	.byte	$4B
	.byte	$02
	.byte	$4C
	.byte	$4C
	.byte	$4C
	.byte	$4C
	.byte	$02
	.byte	$4D
	.byte	$4D
	.byte	$4D
	.byte	$4D
	.byte	$02
	.byte	$4E
	.byte	$4E
	.byte	$4E
	.byte	$4E
	.byte	$02
	.byte	$4F
	.byte	$4F
	.byte	$4F
	.byte	$4F
	.byte	$02
	.byte	$50
	.byte	$50
	.byte	$50
	.byte	$50
	.byte	$02
	.byte	$51
	.byte	$51
	.byte	$51
	.byte	$51
	.byte	$02
	.byte	$52
	.byte	$52
	.byte	$52
	.byte	$52
	.byte	$02
	.byte	$53
	.byte	$53
	.byte	$53
	.byte	$53
	.byte	$02
	.byte	$54
	.byte	$54
	.byte	$54
	.byte	$54
	.byte	$02
	.byte	$55
	.byte	$55
	.byte	$55
	.byte	$55
	.byte	$02
	.byte	$56
	.byte	$56
	.byte	$56
	.byte	$56
	.byte	$02
	.byte	$57
	.byte	$57
	.byte	$57
	.byte	$57
	.byte	$02
	.byte	$58
	.byte	$58
	.byte	$58
	.byte	$58
	.byte	$02
	.byte	$59
	.byte	$59
	.byte	$59
	.byte	$59
	.byte	$02
	.byte	$5A
	.byte	$5A
	.byte	$5A
	.byte	$5A
	.byte	$02
	.byte	$30
	.byte	$30
	.byte	$30
	.byte	$30
	.byte	$02
	.byte	$31
	.byte	$31
	.byte	$31
	.byte	$31
	.byte	$02
	.byte	$32
	.byte	$32
	.byte	$32
	.byte	$32
	.byte	$02
	.byte	$33
	.byte	$33
	.byte	$33
	.byte	$33
	.byte	$02
	.byte	$34
	.byte	$34
	.byte	$34
	.byte	$34
	.byte	$02
	.byte	$04
	.byte	$04
	.byte	$04
	.byte	$04
	.byte	$02
_Room1:
	.byte	$C9
	.byte	$00
	.byte	$02
	.byte	$02
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$03
	.byte	$03
	.byte	$03
	.byte	$03
	.byte	$00
	.byte	$00
	.byte	$02
	.byte	$02
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$01
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$03
	.byte	$03
	.byte	$03
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$03
	.byte	$03
	.byte	$03
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$04
	.byte	$04
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$03
	.byte	$03
	.byte	$03
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$04
	.byte	$04
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$04
	.byte	$04
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$02
	.byte	$02
	.byte	$00
	.byte	$00
	.byte	$02
	.byte	$02
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$04
	.byte	$00
	.byte	$00
	.byte	$02
	.byte	$02
	.byte	$00
	.byte	$00
	.byte	$02
	.byte	$02
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$02
	.byte	$02
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$AF
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$EE
	.byte	$03
	.byte	$03
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$EF
	.byte	$03
	.byte	$03
	.byte	$00
	.byte	$01
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$43
	.byte	$52
	.byte	$80
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$00
	.byte	$04

.segment	"BSS"

.segment	"ZEROPAGE"
_pad1:
	.res	1,$00
_collision:
	.res	1,$00
_collision_L:
	.res	1,$00
_collision_R:
	.res	1,$00
_collision_U:
	.res	1,$00
_collision_D:
	.res	1,$00
_coordinates:
	.res	1,$00
_temp1:
	.res	1,$00
_temp2:
	.res	1,$00
_temp3:
	.res	1,$00
_temp4:
	.res	1,$00
_temp5:
	.res	2,$00
_temp6:
	.res	2,$00
_eject_L:
	.res	1,$00
_eject_R:
	.res	1,$00
_eject_D:
	.res	1,$00
_eject_U:
	.res	1,$00
_direction:
	.res	1,$00
_address:
	.res	2,$00
_x:
	.res	1,$00
_y:
	.res	1,$00
_index:
	.res	1,$00
_map:
	.res	1,$00
_scroll_x:
	.res	2,$00
_scroll_y:
	.res	2,$00
_hero_velocity_x:
	.res	2,$00
_hero_velocity_y:
	.res	2,$00
_old_x:
	.res	2,$00
_old_y:
	.res	2,$00
_temp_x:
	.res	1,$00
_temp_y:
	.res	1,$00
.segment	"BSS"
_c_map:
	.res	240,$00
_c_map2:
	.res	240,$00
_Generic:
	.res	4,$00

; ---------------------------------------------------------------
; void __near__ load_room (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_load_room: near

.segment	"CODE"

;
; set_data_pointer(Room1);
;
	lda     #<(_Room1)
	ldx     #>(_Room1)
	jsr     _set_data_pointer
;
; set_mt_pointer(metatiles1);
;
	lda     #<(_metatiles1)
	ldx     #>(_metatiles1)
	jsr     _set_mt_pointer
;
; for(y=0; ;y+=0x20){
;
	lda     #$00
L0725:	sta     _y
;
; for(x=0; ;x+=0x20){
;
	lda     #$00
L0724:	sta     _x
;
; address = get_ppu_addr(0, x, y);
;
	jsr     decsp2
	lda     #$00
	ldy     #$01
	sta     (sp),y
	lda     _x
	dey
	sta     (sp),y
	lda     _y
	jsr     _get_ppu_addr
	sta     _address
	stx     _address+1
;
; index = (y & 0xf0) + (x >> 4);
;
	lda     _y
	and     #$F0
	sta     ptr1
	lda     _x
	lsr     a
	lsr     a
	lsr     a
	lsr     a
	clc
	adc     ptr1
	sta     _index
;
; buffer_4_mt(address, index); // ppu_address, index to the data
;
	lda     _address
	ldx     _address+1
	jsr     pushax
	lda     _index
	jsr     _buffer_4_mt
;
; flush_vram_update2();
;
	jsr     _flush_vram_update2
;
; if (x == 0xe0) break;
;
	lda     _x
	cmp     #$E0
	beq     L0726
;
; for(x=0; ;x+=0x20){
;
	lda     #$20
	clc
	adc     _x
	jmp     L0724
;
; if (y == 0xe0) break;
;
L0726:	lda     _y
	cmp     #$E0
	beq     L0606
;
; for(y=0; ;y+=0x20){
;
	lda     #$20
	clc
	adc     _y
	jmp     L0725
;
; buffer_1_mt(NTADR_A(8,0), 100);
;
L0606:	ldx     #$20
	lda     #$08
	jsr     pushax
	lda     #$64
	jsr     _buffer_1_mt
;
; buffer_1_mt(NTADR_A(10,0), 200);
;
	ldx     #$20
	lda     #$0A
	jsr     pushax
	lda     #$C8
	jsr     _buffer_1_mt
;
; buffer_1_mt(NTADR_A(12,0), 239); // max number on our list
;
	ldx     #$20
	lda     #$0C
	jsr     pushax
	lda     #$EF
	jsr     _buffer_1_mt
;
; flush_vram_update2();
;
	jsr     _flush_vram_update2
;
; set_vram_update(NULL); // just turn ppu updates OFF for this example
;
	ldx     #$00
	txa
	jsr     _set_vram_update
;
; memcpy (c_map, Room1, 240);
;
	ldy     #$00
L0645:	lda     _Room1,y
	sta     _c_map,y
	iny
	cpy     #$F0
	bne     L0645
;
; }
;
	rts

.endproc

; ---------------------------------------------------------------
; void __near__ draw_sprites (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_draw_sprites: near

.segment	"CODE"

;
; oam_clear();
;
	jsr     _oam_clear
;
; temp_x = BoxGuy1.x >> 8;
;
	lda     _BoxGuy1+1
	sta     _temp_x
;
; temp_y = BoxGuy1.y >> 8;
;
	lda     _BoxGuy1+3
	sta     _temp_y
;
; if(temp_x == 0) temp_x = 1;
;
	lda     _temp_x
	bne     L0727
	lda     #$01
	sta     _temp_x
;
; if(temp_y == 0) temp_y = 1;
;
L0727:	lda     _temp_y
	bne     L0728
	lda     #$01
	sta     _temp_y
;
; if(direction == LEFT) {
;
L0728:	lda     _direction
	bne     L0654
;
; oam_meta_spr(temp_x, temp_y, RoundSprL);
;
	jsr     decsp2
	lda     _temp_x
	ldy     #$01
	sta     (sp),y
	lda     _temp_y
	dey
	sta     (sp),y
	lda     #<(_RoundSprL)
	ldx     #>(_RoundSprL)
	jmp     _oam_meta_spr
;
; oam_meta_spr(temp_x, temp_y, RoundSprR);
;
L0654:	jsr     decsp2
	lda     _temp_x
	ldy     #$01
	sta     (sp),y
	lda     _temp_y
	dey
	sta     (sp),y
	lda     #<(_RoundSprR)
	ldx     #>(_RoundSprR)
	jmp     _oam_meta_spr

.endproc

; ---------------------------------------------------------------
; void __near__ movement (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_movement: near

.segment	"CODE"

;
; old_x = BoxGuy1.x;
;
	lda     _BoxGuy1+1
	sta     _old_x+1
	lda     _BoxGuy1
	sta     _old_x
;
; if(pad1 & PAD_LEFT){
;
	lda     _pad1
	and     #$02
	beq     L072F
;
; direction = LEFT;
;
	lda     #$00
	sta     _direction
;
; hero_velocity_x = -SPEED;
;
	ldx     #$FE
;
; else if (pad1 & PAD_RIGHT){
;
	jmp     L073D
L072F:	lda     _pad1
	ldx     #$00
	and     #$01
	beq     L0731
;
; direction = RIGHT;
;
	lda     #$01
	sta     _direction
;
; hero_velocity_x = SPEED;
;
	inx
L073D:	lda     #$80
;
; hero_velocity_x = 0;
;
L0731:	sta     _hero_velocity_x
	stx     _hero_velocity_x+1
;
; BoxGuy1.x += hero_velocity_x;
;
	lda     _hero_velocity_x
	clc
	adc     _BoxGuy1
	sta     _BoxGuy1
	lda     _hero_velocity_x+1
	adc     _BoxGuy1+1
	sta     _BoxGuy1+1
;
; if(BoxGuy1.x > 0xf100) { // too far, don't wrap around
;
	lda     _BoxGuy1
	cmp     #$01
	lda     _BoxGuy1+1
	sbc     #$F1
	bcc     L0734
;
; if(old_x >= 0x8000){
;
	lda     _old_x
	cmp     #$00
	lda     _old_x+1
	sbc     #$80
	lda     #$00
	tax
	bcc     L0733
;
; BoxGuy1.x = 0xf100; // max right
;
	ldx     #$F1
;
; BoxGuy1.x = 0x0000; // max left
;
L0733:	sta     _BoxGuy1
	stx     _BoxGuy1+1
;
; Generic.x = BoxGuy1.x >> 8; // the collision routine needs an 8 bit value
;
L0734:	lda     _BoxGuy1+1
	sta     _Generic
;
; Generic.y = BoxGuy1.y >> 8;
;
	lda     _BoxGuy1+3
	sta     _Generic+1
;
; Generic.width = HERO_WIDTH;
;
	lda     #$0D
	sta     _Generic+2
;
; Generic.height = HERO_HEIGHT;
;
	sta     _Generic+3
;
; if(hero_velocity_x < 0){ // going left
;
	ldx     _hero_velocity_x+1
	cpx     #$80
	bcc     L0685
;
; if(bg_coll_L() ){ // check collision left
;
	jsr     _bg_coll_L
	tax
	beq     L0691
;
; high_byte(BoxGuy1.x) = high_byte(BoxGuy1.x) - eject_L;
;
	lda     _BoxGuy1+1
	sec
	sbc     _eject_L
;
; else if(hero_velocity_x > 0){ // going right
;
	jmp     L073E
L0685:	lda     _hero_velocity_x
	cmp     #$01
	lda     _hero_velocity_x+1
	sbc     #$00
	bvs     L0690
	eor     #$80
L0690:	bpl     L0691
;
; if(bg_coll_R() ){ // check collision right
;
	jsr     _bg_coll_R
	tax
	beq     L0691
;
; high_byte(BoxGuy1.x) = high_byte(BoxGuy1.x) - eject_R;
;
	lda     _BoxGuy1+1
	sec
	sbc     _eject_R
L073E:	sta     _BoxGuy1+1
;
; old_y = BoxGuy1.y;
;
L0691:	lda     _BoxGuy1+2+1
	sta     _old_y+1
	lda     _BoxGuy1+2
	sta     _old_y
;
; if(pad1 & PAD_UP){
;
	lda     _pad1
	and     #$08
	beq     L0735
;
; hero_velocity_y = -SPEED;
;
	ldx     #$FE
;
; else if (pad1 & PAD_DOWN){
;
	jmp     L073F
L0735:	lda     _pad1
	ldx     #$00
	and     #$04
	beq     L0737
;
; hero_velocity_y = SPEED;
;
	inx
L073F:	lda     #$80
;
; hero_velocity_y = 0;
;
L0737:	sta     _hero_velocity_y
	stx     _hero_velocity_y+1
;
; BoxGuy1.y += hero_velocity_y;
;
	lda     _hero_velocity_y
	clc
	adc     _BoxGuy1+2
	sta     _BoxGuy1+2
	lda     _hero_velocity_y+1
	adc     _BoxGuy1+2+1
	sta     _BoxGuy1+2+1
;
; if(BoxGuy1.y > 0xe000) { // too far, don't wrap around
;
	lda     _BoxGuy1+2
	cmp     #$01
	lda     _BoxGuy1+2+1
	sbc     #$E0
	bcc     L073A
;
; if(old_y >= 0x8000){
;
	lda     _old_y
	cmp     #$00
	lda     _old_y+1
	sbc     #$80
	lda     #$00
	tax
	bcc     L0739
;
; BoxGuy1.y = 0xe000; // max down
;
	ldx     #$E0
;
; BoxGuy1.y = 0x0000; // max up
;
L0739:	sta     _BoxGuy1+2
	stx     _BoxGuy1+2+1
;
; Generic.x = BoxGuy1.x >> 8; // the collision routine needs an 8 bit value
;
L073A:	lda     _BoxGuy1+1
	sta     _Generic
;
; Generic.y = BoxGuy1.y >> 8;
;
	lda     _BoxGuy1+3
	sta     _Generic+1
;
; if(hero_velocity_y < 0){ // going up
;
	ldx     _hero_velocity_y+1
	cpx     #$80
	bcc     L06B4
;
; if(bg_coll_U() ){ // check collision left
;
	jsr     _bg_coll_U
	tax
	beq     L06C0
;
; high_byte(BoxGuy1.y) = high_byte(BoxGuy1.y) - eject_U;
;
	lda     _BoxGuy1+3
	sec
	sbc     _eject_U
;
; else if(hero_velocity_y > 0){ // going down
;
	jmp     L0740
L06B4:	lda     _hero_velocity_y
	cmp     #$01
	lda     _hero_velocity_y+1
	sbc     #$00
	bvs     L06BF
	eor     #$80
L06BF:	bpl     L06C0
;
; if(bg_coll_D() ){ // check collision right
;
	jsr     _bg_coll_D
	tax
	beq     L06C0
;
; high_byte(BoxGuy1.y) = high_byte(BoxGuy1.y) - eject_D;
;
	lda     _BoxGuy1+3
	sec
	sbc     _eject_D
L0740:	sta     _BoxGuy1+3
;
; } 
;
L06C0:	rts

.endproc

; ---------------------------------------------------------------
; char __near__ bg_collision_sub (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_bg_collision_sub: near

.segment	"CODE"

;
; if(temp_y >= 0xf0) return 0;
;
	lda     _temp_y
	cmp     #$F0
	ldx     #$00
	bcc     L0742
	txa
	rts
;
; coordinates = (temp_x >> 4) + (temp_y & 0xf0);
;
L0742:	lda     _temp_x
	lsr     a
	lsr     a
	lsr     a
	lsr     a
	sta     ptr1
	lda     _temp_y
	and     #$F0
	clc
	adc     ptr1
	sta     _coordinates
;
; collision = c_map[coordinates];
;
	ldy     _coordinates
	lda     _c_map,y
	sta     _collision
;
; }
;
	rts

.endproc

; ---------------------------------------------------------------
; char __near__ bg_coll_L (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_bg_coll_L: near

.segment	"CODE"

;
; temp_x = Generic.x;
;
	lda     _Generic
	sta     _temp_x
;
; eject_L = temp_x | 0xf0;
;
	ora     #$F0
	sta     _eject_L
;
; temp_y = Generic.y + 2;
;
	lda     _Generic+1
	clc
	adc     #$02
	sta     _temp_y
;
; if(bg_collision_sub() ) return 1;
;
	jsr     _bg_collision_sub
	tax
	beq     L0745
	ldx     #$00
	lda     #$01
	rts
;
; temp_y = Generic.y + Generic.height;
;
L0745:	lda     _Generic+1
	clc
	adc     _Generic+3
	sta     _temp_y
;
; temp_y -= 2;
;
	sec
	sbc     #$02
	sta     _temp_y
;
; if(bg_collision_sub() ) return 1;
;
	jsr     _bg_collision_sub
	tax
	beq     L0747
	ldx     #$00
	lda     #$01
	rts
;
; }
;
L0747:	rts

.endproc

; ---------------------------------------------------------------
; char __near__ bg_coll_R (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_bg_coll_R: near

.segment	"CODE"

;
; temp_x = Generic.x + Generic.width;
;
	lda     _Generic
	clc
	adc     _Generic+2
	sta     _temp_x
;
; eject_R = (temp_x + 1) & 0x0f;
;
	clc
	adc     #$01
	and     #$0F
	sta     _eject_R
;
; temp_y = Generic.y + 2;
;
	lda     _Generic+1
	clc
	adc     #$02
	sta     _temp_y
;
; if(bg_collision_sub() ) return 1;
;
	jsr     _bg_collision_sub
	tax
	beq     L074A
	ldx     #$00
	lda     #$01
	rts
;
; temp_y = Generic.y + Generic.height;
;
L074A:	lda     _Generic+1
	clc
	adc     _Generic+3
	sta     _temp_y
;
; temp_y -= 2;
;
	sec
	sbc     #$02
	sta     _temp_y
;
; if(bg_collision_sub() ) return 1;
;
	jsr     _bg_collision_sub
	tax
	beq     L074C
	ldx     #$00
	lda     #$01
	rts
;
; }
;
L074C:	rts

.endproc

; ---------------------------------------------------------------
; char __near__ bg_coll_U (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_bg_coll_U: near

.segment	"CODE"

;
; temp_x = Generic.x + 2;
;
	lda     _Generic
	clc
	adc     #$02
	sta     _temp_x
;
; temp_y = Generic.y;
;
	lda     _Generic+1
	sta     _temp_y
;
; eject_U = temp_y | 0xf0;
;
	ora     #$F0
	sta     _eject_U
;
; if(bg_collision_sub() ) return 1;
;
	jsr     _bg_collision_sub
	tax
	beq     L074E
	ldx     #$00
	lda     #$01
	rts
;
; temp_x = Generic.x + Generic.width;
;
L074E:	lda     _Generic
	clc
	adc     _Generic+2
	sta     _temp_x
;
; temp_x -= 2;
;
	sec
	sbc     #$02
	sta     _temp_x
;
; if(bg_collision_sub() ) return 1;
;
	jsr     _bg_collision_sub
	tax
	beq     L0750
	ldx     #$00
	lda     #$01
	rts
;
; }
;
L0750:	rts

.endproc

; ---------------------------------------------------------------
; char __near__ bg_coll_D (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_bg_coll_D: near

.segment	"CODE"

;
; temp_x = Generic.x + 2;
;
	lda     _Generic
	clc
	adc     #$02
	sta     _temp_x
;
; temp_y = Generic.y + Generic.height;
;
	lda     _Generic+1
	clc
	adc     _Generic+3
	sta     _temp_y
;
; eject_D = (temp_y + 1) & 0x0f;
;
	clc
	adc     #$01
	and     #$0F
	sta     _eject_D
;
; if(bg_collision_sub() ) return 1;
;
	jsr     _bg_collision_sub
	tax
	beq     L0753
	ldx     #$00
	lda     #$01
	rts
;
; temp_x = Generic.x + Generic.width;
;
L0753:	lda     _Generic
	clc
	adc     _Generic+2
	sta     _temp_x
;
; temp_x -= 2;
;
	sec
	sbc     #$02
	sta     _temp_x
;
; if(bg_collision_sub() ) return 1;
;
	jsr     _bg_collision_sub
	tax
	beq     L0755
	ldx     #$00
	lda     #$01
	rts
;
; }
;
L0755:	rts

.endproc

; ---------------------------------------------------------------
; void __near__ main (void)
; ---------------------------------------------------------------

.segment	"CODE"

.proc	_main: near

.segment	"CODE"

;
; ppu_off(); // screen off
;
	jsr     _ppu_off
;
; pal_bg(palette_bg);
;
	lda     #<(_palette_bg)
	ldx     #>(_palette_bg)
	jsr     _pal_bg
;
; pal_spr(palette_sp);
;
	lda     #<(_palette_sp)
	ldx     #>(_palette_sp)
	jsr     _pal_spr
;
; bank_spr(1);
;
	lda     #$01
	jsr     _bank_spr
;
; set_vram_buffer(); // do at least once, sets a pointer to a buffer
;
	jsr     _set_vram_buffer
;
; load_room();
;
	jsr     _load_room
;
; set_scroll_y(0xff); // shift the bg down 1 pixel
;
	ldx     #$00
	lda     #$FF
	jsr     _set_scroll_y
;
; ppu_on_all(); // turn on screen
;
	jsr     _ppu_on_all
;
; ppu_wait_nmi(); // wait till beginning of the frame
;
L05F6:	jsr     _ppu_wait_nmi
;
; pad1 = pad_poll(0); // read the first controller
;
	lda     #$00
	jsr     _pad_poll
	sta     _pad1
;
; movement();
;
	jsr     _movement
;
; draw_sprites();
;
	jsr     _draw_sprites
;
; while (1){
;
	jmp     L05F6

.endproc

