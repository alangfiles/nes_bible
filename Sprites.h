// a 16x16 pixel metasprite
// const unsigned char MosesStandL[] = {
// 		0, 0, 0x00, 0,
// 		8, 0, 0x01, 0,
// 		0, 8, 0x10, 0,
// 		8, 8, 0x11, 0,
// 		0, 16, 0x20, 0,
// 		8, 16, 0x21, 0,
// 		128};
// const unsigned char MosesStandR[] = {
// 		0, 0, 0x01, 0 | OAM_FLIP_H,
// 		8, 0, 0x00, 0 | OAM_FLIP_H,
// 		0, 8, 0x11, 0 | OAM_FLIP_H,
// 		8, 8, 0x10, 0 | OAM_FLIP_H,
// 		0, 16, 0x21, 0 | OAM_FLIP_H,
// 		8, 16, 0x20, 0 | OAM_FLIP_H,
// 		128};
// const unsigned char MosesMoveL1[] = {
// 		0, 0, 0x00, 0,
// 		8, 0, 0x01, 0,
// 		0, 8, 0x30, 0,
// 		8, 8, 0x31, 0,
// 		0, 16, 0x40, 0,
// 		8, 16, 0x41, 0,
// 		128};
// const unsigned char MosesMoveL2[] = {
// 		0, 0, 0x00, 0,
// 		8, 0, 0x01, 0,
// 		0, 8, 0x32, 0,
// 		8, 8, 0x33, 0,
// 		0, 16, 0x42, 0,
// 		8, 16, 0x43, 0,
// 		128};
// const unsigned char MosesMoveL3[] = {
// 		0, 0, 0x00, 0,
// 		8, 0, 0x01, 0,
// 		-8, 8, 0x34, 0, // extra
// 		0, 8, 0x35, 0,
// 		8, 8, 0x36, 0,
// 		0, 16, 0x45, 0,
// 		8, 16, 0x46, 0,
// 		16, 16, 0x47, 0, // extra
// 		128};
// const unsigned char MosesMoveL4[] = {
// 		0, 0, 0x00, 0,
// 		8, 0, 0x01, 0,
// 		0, 8, 0x38, 0,
// 		8, 8, 0x39, 0,
// 		0, 16, 0x48, 0,
// 		8, 16, 0x49, 0,
// 		16, 16, 0x4a, 0, // extra
// 		128};
// const unsigned char MosesMoveL5[] = {
// 		0, 0, 0x00, 0,
// 		8, 0, 0x01, 0,
// 		0, 8, 0x3b, 0,
// 		8, 8, 0x3c, 0,
// 		0, 16, 0x4b, 0,
// 		8, 16, 0x4c, 0,
// 		16, 16, 0x4d, 0, // extra
// 		128};
// const unsigned char MosesMoveR1[] = {
// 		0, 0, 0x01, 0 | OAM_FLIP_H,
// 		8, 0, 0x00, 0 | OAM_FLIP_H,
// 		0, 8, 0x31, 0 | OAM_FLIP_H,
// 		8, 8, 0x30, 0 | OAM_FLIP_H,
// 		0, 16, 0x41, 0 | OAM_FLIP_H,
// 		8, 16, 0x40, 0 | OAM_FLIP_H,
// 		128};
// const unsigned char MosesMoveR2[] = {
// 		0, 0, 0x01, 0 | OAM_FLIP_H,
// 		8, 0, 0x00, 0 | OAM_FLIP_H,
// 		0, 8, 0x33, 0 | OAM_FLIP_H,
// 		8, 8, 0x32, 0 | OAM_FLIP_H,
// 		0, 16, 0x43, 0 | OAM_FLIP_H,
// 		8, 16, 0x42, 0 | OAM_FLIP_H,
// 		128};
// const unsigned char MosesMoveR3[] = {
// 		0, 0, 0x01, 0 | OAM_FLIP_H,
// 		8, 0, 0x00, 0 | OAM_FLIP_H,
// 		16, 8, 0x34, 0 | OAM_FLIP_H, // extra
// 		0, 8, 0x36, 0 | OAM_FLIP_H,
// 		8, 8, 0x35, 0 | OAM_FLIP_H,
// 		0, 16, 0x46, 0 | OAM_FLIP_H,
// 		8, 16, 0x45, 0 | OAM_FLIP_H,
// 		-8, 16, 0x47, 0 | OAM_FLIP_H, // extra
// 		128};
// const unsigned char MosesMoveR4[] = {
// 		0, 0, 0x01, 0 | OAM_FLIP_H,
// 		8, 0, 0x00, 0 | OAM_FLIP_H,
// 		0, 8, 0x39, 0 | OAM_FLIP_H,
// 		8, 8, 0x38, 0 | OAM_FLIP_H,
// 		0, 16, 0x49, 0 | OAM_FLIP_H,
// 		8, 16, 0x48, 0 | OAM_FLIP_H,
// 		-8, 16, 0x4a, 0 | OAM_FLIP_H, // extra
// 		128};
// const unsigned char MosesMoveR5[] = {
// 		0, 0, 0x01, 0 | OAM_FLIP_H,
// 		8, 0, 0x00, 0 | OAM_FLIP_H,
// 		0, 8, 0x3c, 0 | OAM_FLIP_H,
// 		8, 8, 0x3b, 0 | OAM_FLIP_H,
// 		0, 16, 0x4c, 0 | OAM_FLIP_H,
// 		8, 16, 0x4b, 0 | OAM_FLIP_H,
// 		-8, 16, 0x4d, 0 | OAM_FLIP_H, // extra
// 		128};
const unsigned char orb[] = {
		0, 0, 0x1c, 0,
		0x80};
const unsigned char orb1[] = {
		0, 0, 0x0c, 0,
		0x80};
const unsigned char orb2[] = {
		0, 0, 0x0d, 0,
		0x80};
const unsigned char orb3[] = {
		0, 0, 0x0e, 0,
		0x80};
const unsigned char orb4[] = {
		0, 0, 0x0f, 0,
		0x80};
const unsigned char orb5[] = {
		0, 0, 0x1f, 0,
		0x80};
const unsigned char orb6[] = {
		0, 0, 0x1e, 0,
		0x80};
const unsigned char orb7[] = {
		0, 0, 0x1d, 0,
		0x80};
const unsigned char mosesclimb1[] = {
		8, -8, 0x06, 0,
		16, -8, 0x03, 0,
		8, 0, 0x16, 0,
		16, 0, 0x13, 0,
		8, 8, 0x26, 0,
		16, 8, 0x23, 0,
		0x80};
const unsigned char mosesclimb2[] = {
		8, -8, 0x04, 0,
		16, -8, 0x05, 0,
		8, 0, 0x14, 0,
		16, 0, 0x15, 0,
		8, 8, 0x24, 0,
		16, 8, 0x25, 0,
		0x80};
const unsigned char mosesclimb3[] = {
		8, -8, 0x02, 0,
		16, -8, 0x07, 0,
		8, 0, 0x12, 0,
		16, 0, 0x17, 0,
		8, 8, 0x22, 0,
		16, 8, 0x27, 0,
		0x80};
const unsigned char mosesstandright[] = {
		16, -8, 0x00, 0 | OAM_FLIP_H,
		8, -8, 0x01, 0 | OAM_FLIP_H,
		16, 0, 0x10, 0 | OAM_FLIP_H,
		8, 0, 0x11, 0 | OAM_FLIP_H,
		16, 8, 0x20, 0 | OAM_FLIP_H,
		8, 8, 0x21, 0 | OAM_FLIP_H,
		12, -7, 0x0b, 2 | OAM_FLIP_H,
		0x80};
const unsigned char mosesstandleft[] = {
		8, -8, 0x00, 0,
		16, -8, 0x01, 0,
		8, 0, 0x10, 0,
		16, 0, 0x11, 0,
		8, 8, 0x20, 0,
		16, 8, 0x21, 0,
		12, -7, 0x0b, 2,
		0x80};
const unsigned char mosesstandshootleft[] = {
		8, -8, 0x00, 0,
		16, -8, 0x01, 0,
		8, 0, 0x09, 0,
		16, 0, 0x11, 0,
		8, 8, 0x20, 0,
		16, 8, 0x21, 0,
		12, -7, 0x0b, 2,
		0, 0, 0x08, 0,
		0x80};
const unsigned char mosesstandshootright[] = {
		16, -8, 0x00, 0 | OAM_FLIP_H,
		8, -8, 0x01, 0 | OAM_FLIP_H,
		16, 0, 0x09, 0 | OAM_FLIP_H,
		8, 0, 0x11, 0 | OAM_FLIP_H,
		16, 8, 0x20, 0 | OAM_FLIP_H,
		8, 8, 0x21, 0 | OAM_FLIP_H,
		12, -7, 0x0b, 2 | OAM_FLIP_H,
		24, 0, 0x08, 0 | OAM_FLIP_H,
		0x80};
const unsigned char mosesrun1left[] = {
		8, -8, 0x00, 0,
		16, -8, 0x01, 0,
		8, 0, 0x35, 0,
		16, 0, 0x36, 0,
		8, 8, 0x45, 0,
		16, 8, 0x46, 0,
		12, -7, 0x0b, 2,
		24, 8, 0x47, 0,
		0, 0, 0x34, 0,
		0x80};
const unsigned char mosesrun2left[] = {
		8, -8, 0x00, 0,
		16, -8, 0x01, 0,
		8, 0, 0x32, 0,
		16, 0, 0x33, 0,
		8, 8, 0x42, 0,
		16, 8, 0x43, 0,
		12, -7, 0x0b, 2,
		8, 0, 0x34, 0,
		0x80};
const unsigned char mosesrun3left[] = {
		8, -8, 0x00, 0,
		16, -8, 0x01, 0,
		8, 0, 0x30, 0,
		16, 0, 0x31, 0,
		8, 8, 0x40, 0,
		16, 8, 0x41, 0,
		12, -7, 0x0b, 2,
		8, 0, 0x34, 0,
		0x80};
const unsigned char mosesrun4left[] = {
		8, -8, 0x00, 0,
		16, -8, 0x01, 0,
		8, 0, 0x38, 0,
		16, 0, 0x39, 0,
		8, 8, 0x48, 0,
		16, 8, 0x49, 0,
		12, -7, 0x0b, 2,
		8, 0, 0x34, 0,
		0x80};
const unsigned char mosesrun5left[] = {
		8, -8, 0x00, 0,
		16, -8, 0x01, 0,
		8, 0, 0x3b, 0,
		16, 0, 0x3c, 0,
		8, 8, 0x4b, 0,
		16, 8, 0x4c, 0,
		12, -7, 0x0b, 2,
		8, 0, 0x34, 0,
		24, 8, 0x4d, 0,
		0x80};
const unsigned char mosesrun1right[] = {
		16, -8, 0x00, 0 | OAM_FLIP_H,
		8, -8, 0x01, 0 | OAM_FLIP_H,
		16, 0, 0x35, 0 | OAM_FLIP_H,
		8, 0, 0x36, 0 | OAM_FLIP_H,
		16, 8, 0x45, 0 | OAM_FLIP_H,
		8, 8, 0x46, 0 | OAM_FLIP_H,
		12, -7, 0x0b, 2 | OAM_FLIP_H,
		0, 8, 0x47, 0 | OAM_FLIP_H,
		24, 0, 0x34, 0 | OAM_FLIP_H,
		0x80};
const unsigned char mosesrun2right[] = {
		16, -8, 0x00, 0 | OAM_FLIP_H,
		8, -8, 0x01, 0 | OAM_FLIP_H,
		16, 0, 0x32, 0 | OAM_FLIP_H,
		8, 0, 0x33, 0 | OAM_FLIP_H,
		16, 8, 0x42, 0 | OAM_FLIP_H,
		8, 8, 0x43, 0 | OAM_FLIP_H,
		12, -7, 0x0b, 2 | OAM_FLIP_H,
		16, 0, 0x34, 0 | OAM_FLIP_H,
		0x80};
const unsigned char mosesrun3right[] = {
		16, -8, 0x00, 0 | OAM_FLIP_H,
		8, -8, 0x01, 0 | OAM_FLIP_H,
		16, 0, 0x30, 0 | OAM_FLIP_H,
		8, 0, 0x31, 0 | OAM_FLIP_H,
		16, 8, 0x40, 0 | OAM_FLIP_H,
		8, 8, 0x41, 0 | OAM_FLIP_H,
		12, -7, 0x0b, 2 | OAM_FLIP_H,
		16, 0, 0x34, 0 | OAM_FLIP_H,
		0x80};
const unsigned char mosesrun4right[] = {
		16, -8, 0x00, 0 | OAM_FLIP_H,
		8, -8, 0x01, 0 | OAM_FLIP_H,
		16, 0, 0x38, 0 | OAM_FLIP_H,
		8, 0, 0x39, 0 | OAM_FLIP_H,
		16, 8, 0x48, 0 | OAM_FLIP_H,
		8, 8, 0x49, 0 | OAM_FLIP_H,
		12, -7, 0x0b, 2 | OAM_FLIP_H,
		16, 0, 0x34, 0 | OAM_FLIP_H,
		0x80};
const unsigned char mosesrun5right[] = {
		16, -8, 0x00, 0 | OAM_FLIP_H,
		8, -8, 0x01, 0 | OAM_FLIP_H,
		16, 0, 0x3b, 0 | OAM_FLIP_H,
		8, 0, 0x3c, 0 | OAM_FLIP_H,
		16, 8, 0x4b, 0 | OAM_FLIP_H,
		8, 8, 0x4c, 0 | OAM_FLIP_H,
		12, -7, 0x0b, 2 | OAM_FLIP_H,
		16, 0, 0x34, 0 | OAM_FLIP_H,
		0, 8, 0x4d, 0 | OAM_FLIP_H,
		0x80};
const unsigned char mosesrunshoot1left[] = {
		8, -8, 0x00, 0,
		16, -8, 0x01, 0,
		8, 0, 0x09, 0,
		16, 0, 0x36, 0,
		8, 8, 0x45, 0,
		16, 8, 0x46, 0,
		12, -7, 0x0b, 2,
		24, 8, 0x47, 0,
		0, 0, 0x08, 0,
		0x80};
const unsigned char mosesrunshoot2left[] = {
		8, -8, 0x00, 0,
		16, -8, 0x01, 0,
		8, 0, 0x09, 0,
		16, 0, 0x36, 0,
		8, 8, 0x42, 0,
		16, 8, 0x43, 0,
		12, -7, 0x0b, 2,
		0, 0, 0x08, 0,
		0x80};
const unsigned char mosesrunshoot3left[] = {
		8, -8, 0x00, 0,
		16, -8, 0x01, 0,
		8, 0, 0x09, 0,
		16, 0, 0x31, 0,
		8, 8, 0x40, 0,
		16, 8, 0x41, 0,
		12, -7, 0x0b, 2,
		0, 0, 0x08, 0,
		0x80};
const unsigned char mosesrunshoot4left[] = {
		8, -8, 0x00, 0,
		16, -8, 0x01, 0,
		8, 0, 0x09, 0,
		16, 0, 0x39, 0,
		8, 8, 0x48, 0,
		16, 8, 0x49, 0,
		12, -7, 0x0b, 2,
		0, 0, 0x08, 0,
		0x80};
const unsigned char mosesrunshoot5left[] = {
		8, -8, 0x00, 0,
		16, -8, 0x01, 0,
		8, 0, 0x09, 0,
		16, 0, 0x3c, 0,
		8, 8, 0x4b, 0,
		16, 8, 0x4c, 0,
		12, -7, 0x0b, 2,
		24, 8, 0x4d, 0,
		0, 0, 0x08, 0,
		0x80};
const unsigned char mosesrunshoot1right[] = {
		16, -8, 0x00, 0 | OAM_FLIP_H,
		8, -8, 0x01, 0 | OAM_FLIP_H,
		16, 0, 0x09, 0 | OAM_FLIP_H,
		8, 0, 0x36, 0 | OAM_FLIP_H,
		16, 8, 0x45, 0 | OAM_FLIP_H,
		8, 8, 0x46, 0 | OAM_FLIP_H,
		12, -7, 0x0b, 2 | OAM_FLIP_H,
		0, 8, 0x47, 0 | OAM_FLIP_H,
		24, 0, 0x08, 0 | OAM_FLIP_H,
		0x80};
const unsigned char mosesrunshoot2right[] = {
		16, -8, 0x00, 0 | OAM_FLIP_H,
		8, -8, 0x01, 0 | OAM_FLIP_H,
		16, 0, 0x09, 0 | OAM_FLIP_H,
		8, 0, 0x36, 0 | OAM_FLIP_H,
		16, 8, 0x42, 0 | OAM_FLIP_H,
		8, 8, 0x43, 0 | OAM_FLIP_H,
		12, -7, 0x0b, 2 | OAM_FLIP_H,
		24, 0, 0x08, 0 | OAM_FLIP_H,
		0x80};
const unsigned char mosesrunshoot3right[] = {
		16, -8, 0x00, 0 | OAM_FLIP_H,
		8, -8, 0x01, 0 | OAM_FLIP_H,
		16, 0, 0x09, 0 | OAM_FLIP_H,
		8, 0, 0x31, 0 | OAM_FLIP_H,
		16, 8, 0x40, 0 | OAM_FLIP_H,
		8, 8, 0x41, 0 | OAM_FLIP_H,
		12, -7, 0x0b, 2 | OAM_FLIP_H,
		24, 0, 0x08, 0 | OAM_FLIP_H,
		0x80};
const unsigned char mosesrunshoot4right[] = {
		16, -8, 0x00, 0 | OAM_FLIP_H,
		8, -8, 0x01, 0 | OAM_FLIP_H,
		16, 0, 0x09, 0 | OAM_FLIP_H,
		8, 0, 0x39, 0 | OAM_FLIP_H,
		16, 8, 0x48, 0 | OAM_FLIP_H,
		8, 8, 0x49, 0 | OAM_FLIP_H,
		12, -7, 0x0b, 2 | OAM_FLIP_H,
		24, 0, 0x08, 0 | OAM_FLIP_H,
		0x80};
const unsigned char mosesrunshoot5right[] = {
		16, -8, 0x00, 0 | OAM_FLIP_H,
		8, -8, 0x01, 0 | OAM_FLIP_H,
		16, 0, 0x09, 0 | OAM_FLIP_H,
		8, 0, 0x3c, 0 | OAM_FLIP_H,
		16, 8, 0x4b, 0 | OAM_FLIP_H,
		8, 8, 0x4c, 0 | OAM_FLIP_H,
		12, -7, 0x0b, 2 | OAM_FLIP_H,
		0, 8, 0x4d, 0 | OAM_FLIP_H,
		24, 0, 0x08, 0 | OAM_FLIP_H,
		0x80};
const unsigned char mosesjumpleft[] = {
		8, -8, 0x55, 0,
		16, -8, 0x56, 0,
		8, 0, 0x65, 0,
		16, 0, 0x66, 0,
		8, 8, 0x75, 0,
		16, 8, 0x76, 0,
		12, -7, 0x0b, 2,
		0x80};
const unsigned char mosesjumpleftshoot[] = {
		8, -8, 0x00, 0,
		16, -8, 0x56, 0,
		8, 0, 0x09, 0,
		16, 0, 0x66, 0,
		8, 8, 0x75, 0,
		16, 8, 0x76, 0,
		12, -7, 0x0b, 2,
		0, 0, 0x08, 0,
		0x80};
const unsigned char mosesjumpright[] = {
		16, -8, 0x55, 0 | OAM_FLIP_H,
		8, -8, 0x56, 0 | OAM_FLIP_H,
		16, 0, 0x65, 0 | OAM_FLIP_H,
		8, 0, 0x66, 0 | OAM_FLIP_H,
		16, 8, 0x75, 0 | OAM_FLIP_H,
		8, 8, 0x76, 0 | OAM_FLIP_H,
		12, -7, 0x0b, 2 | OAM_FLIP_H,
		0x80};
const unsigned char mosesjumprightshoot[] = {
		16, -8, 0x00, 0 | OAM_FLIP_H,
		8, -8, 0x56, 0 | OAM_FLIP_H,
		16, 0, 0x09, 0 | OAM_FLIP_H,
		8, 0, 0x66, 0 | OAM_FLIP_H,
		16, 8, 0x75, 0 | OAM_FLIP_H,
		8, 8, 0x76, 0 | OAM_FLIP_H,
		12, -7, 0x0b, 2 | OAM_FLIP_H,
		24, 0, 0x08, 0 | OAM_FLIP_H,
		0x80};
const unsigned char mosesfallwiggle1left[] = {
		8, -8, 0x55, 0,
		16, -8, 0x58, 0,
		8, 0, 0x65, 0,
		16, 0, 0x68, 0,
		8, 8, 0x75, 0,
		16, 8, 0x78, 0,
		12, -7, 0x0b, 2,
		0x80};
const unsigned char mosesfallwiggle2left[] = {
		8, -8, 0x57, 0,
		16, -8, 0x56, 0,
		8, 0, 0x67, 0,
		16, 0, 0x66, 0,
		8, 8, 0x77, 0,
		16, 8, 0x76, 0,
		12, -7, 0x0b, 2,
		0x80};
const unsigned char mosesfallwiggle1leftshoot[] = {
		8, -8, 0x00, 0,
		16, -8, 0x58, 0,
		8, 0, 0x09, 0,
		16, 0, 0x68, 0,
		8, 8, 0x75, 0,
		16, 8, 0x78, 0,
		12, -7, 0x0b, 2,
		0, 0, 0x08, 0,
		0x80};
const unsigned char mosesfallwiggle2leftshoot[] = {
		8, -8, 0x00, 0,
		16, -8, 0x56, 0,
		8, 0, 0x09, 0,
		16, 0, 0x66, 0,
		8, 8, 0x77, 0,
		16, 8, 0x76, 0,
		12, -7, 0x0b, 2,
		0, 0, 0x08, 0,
		0x80};
const unsigned char mosesfallwiggle1right[] = {
		16, -8, 0x55, 0 | OAM_FLIP_H,
		8, -8, 0x58, 0 | OAM_FLIP_H,
		16, 0, 0x65, 0 | OAM_FLIP_H,
		8, 0, 0x68, 0 | OAM_FLIP_H,
		16, 8, 0x75, 0 | OAM_FLIP_H,
		8, 8, 0x78, 0 | OAM_FLIP_H,
		12, -7, 0x0b, 2 | OAM_FLIP_H,
		0x80};
const unsigned char mosesfallwiggle2right[] = {
		16, -8, 0x57, 0 | OAM_FLIP_H,
		8, -8, 0x56, 0 | OAM_FLIP_H,
		16, 0, 0x67, 0 | OAM_FLIP_H,
		8, 0, 0x66, 0 | OAM_FLIP_H,
		16, 8, 0x77, 0 | OAM_FLIP_H,
		8, 8, 0x76, 0 | OAM_FLIP_H,
		12, -7, 0x0b, 2 | OAM_FLIP_H,
		0x80};
const unsigned char mosesfallwiggle1rightshoot[] = {
		16, -8, 0x00, 0 | OAM_FLIP_H,
		8, -8, 0x58, 0 | OAM_FLIP_H,
		16, 0, 0x09, 0 | OAM_FLIP_H,
		8, 0, 0x68, 0 | OAM_FLIP_H,
		16, 8, 0x75, 0 | OAM_FLIP_H,
		8, 8, 0x78, 0 | OAM_FLIP_H,
		12, -7, 0x0b, 2 | OAM_FLIP_H,
		24, 0, 0x08, 0 | OAM_FLIP_H,
		0x80};
const unsigned char mosesfallwiggle2rightshoot[] = {
		8, -8, 0x00, 0,
		16, -8, 0x56, 0,
		8, 0, 0x09, 0,
		16, 0, 0x66, 0,
		8, 8, 0x77, 0,
		16, 8, 0x76, 0,
		12, -7, 0x0b, 2,
		0, 0, 0x08, 0,
		0x80};
