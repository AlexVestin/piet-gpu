// SPDX-License-Identifier: Apache-2.0 OR MIT OR Unlicense

// Code auto-generated by piet-gpu-derive

struct CmdStrokeRef {
    uint offset;
};

struct CmdFillRef {
    uint offset;
};

struct CmdColorRef {
    uint offset;
};

struct CmdLinGradRef {
    uint offset;
};

struct CmdRadGradRef {
    uint offset;
};

struct CmdImageRef {
    uint offset;
};

struct CmdAlphaRef {
    uint offset;
};

struct CmdEndClipRef {
    uint offset;
};

struct CmdJumpRef {
    uint offset;
};

struct CmdRef {
    uint offset;
};

struct CmdStroke {
    uint tile_ref;
    float half_width;
};

#define CmdStroke_size 8

CmdStrokeRef CmdStroke_index(CmdStrokeRef ref, uint index) {
    return CmdStrokeRef(ref.offset + index * CmdStroke_size);
}

struct CmdFill {
    uint tile_ref;
    int backdrop;
};

#define CmdFill_size 8

CmdFillRef CmdFill_index(CmdFillRef ref, uint index) {
    return CmdFillRef(ref.offset + index * CmdFill_size);
}

struct CmdColor {
    uint rgba_color;
};

#define CmdColor_size 4

CmdColorRef CmdColor_index(CmdColorRef ref, uint index) {
    return CmdColorRef(ref.offset + index * CmdColor_size);
}

struct CmdLinGrad {
    uint index;
    float line_x;
    float line_y;
    float line_c;
};

#define CmdLinGrad_size 16

CmdLinGradRef CmdLinGrad_index(CmdLinGradRef ref, uint index) {
    return CmdLinGradRef(ref.offset + index * CmdLinGrad_size);
}

struct CmdRadGrad {
    uint index;
    vec4 mat;
    vec2 xlat;
    vec2 c1;
    float ra;
    float roff;
};

#define CmdRadGrad_size 44

CmdRadGradRef CmdRadGrad_index(CmdRadGradRef ref, uint index) {
    return CmdRadGradRef(ref.offset + index * CmdRadGrad_size);
}

struct CmdImage {
    uint index;
    ivec2 offset;
};

#define CmdImage_size 8

CmdImageRef CmdImage_index(CmdImageRef ref, uint index) {
    return CmdImageRef(ref.offset + index * CmdImage_size);
}

struct CmdAlpha {
    float alpha;
};

#define CmdAlpha_size 4

CmdAlphaRef CmdAlpha_index(CmdAlphaRef ref, uint index) {
    return CmdAlphaRef(ref.offset + index * CmdAlpha_size);
}

struct CmdEndClip {
    uint blend;
};

#define CmdEndClip_size 4

CmdEndClipRef CmdEndClip_index(CmdEndClipRef ref, uint index) {
    return CmdEndClipRef(ref.offset + index * CmdEndClip_size);
}

struct CmdJump {
    uint new_ref;
};

#define CmdJump_size 4

CmdJumpRef CmdJump_index(CmdJumpRef ref, uint index) {
    return CmdJumpRef(ref.offset + index * CmdJump_size);
}

#define Cmd_End 0
#define Cmd_Fill 1
#define Cmd_Stroke 2
#define Cmd_Solid 3
#define Cmd_Alpha 4
#define Cmd_Color 5
#define Cmd_LinGrad 6
#define Cmd_RadGrad 7
#define Cmd_Image 8
#define Cmd_BeginClip 9
#define Cmd_EndClip 10
#define Cmd_Jump 11
#define Cmd_size 48

CmdRef Cmd_index(CmdRef ref, uint index) {
    return CmdRef(ref.offset + index * Cmd_size);
}

struct CmdTag {
   uint tag;
   uint flags;
};

CmdStroke CmdStroke_read(Alloc a, CmdStrokeRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    uint raw1 = read_mem(a, ix + 1);
    CmdStroke s;
    s.tile_ref = raw0;
    s.half_width = uintBitsToFloat(raw1);
    return s;
}

void CmdStroke_write(Alloc a, CmdStrokeRef ref, CmdStroke s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, s.tile_ref);
    write_mem(a, ix + 1, floatBitsToUint(s.half_width));
}

CmdFill CmdFill_read(Alloc a, CmdFillRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    uint raw1 = read_mem(a, ix + 1);
    CmdFill s;
    s.tile_ref = raw0;
    s.backdrop = int(raw1);
    return s;
}

void CmdFill_write(Alloc a, CmdFillRef ref, CmdFill s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, s.tile_ref);
    write_mem(a, ix + 1, uint(s.backdrop));
}

CmdColor CmdColor_read(Alloc a, CmdColorRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    CmdColor s;
    s.rgba_color = raw0;
    return s;
}

void CmdColor_write(Alloc a, CmdColorRef ref, CmdColor s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, s.rgba_color);
}

CmdLinGrad CmdLinGrad_read(Alloc a, CmdLinGradRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    uint raw1 = read_mem(a, ix + 1);
    uint raw2 = read_mem(a, ix + 2);
    uint raw3 = read_mem(a, ix + 3);
    CmdLinGrad s;
    s.index = raw0;
    s.line_x = uintBitsToFloat(raw1);
    s.line_y = uintBitsToFloat(raw2);
    s.line_c = uintBitsToFloat(raw3);
    return s;
}

void CmdLinGrad_write(Alloc a, CmdLinGradRef ref, CmdLinGrad s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, s.index);
    write_mem(a, ix + 1, floatBitsToUint(s.line_x));
    write_mem(a, ix + 2, floatBitsToUint(s.line_y));
    write_mem(a, ix + 3, floatBitsToUint(s.line_c));
}

CmdRadGrad CmdRadGrad_read(Alloc a, CmdRadGradRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    uint raw1 = read_mem(a, ix + 1);
    uint raw2 = read_mem(a, ix + 2);
    uint raw3 = read_mem(a, ix + 3);
    uint raw4 = read_mem(a, ix + 4);
    uint raw5 = read_mem(a, ix + 5);
    uint raw6 = read_mem(a, ix + 6);
    uint raw7 = read_mem(a, ix + 7);
    uint raw8 = read_mem(a, ix + 8);
    uint raw9 = read_mem(a, ix + 9);
    uint raw10 = read_mem(a, ix + 10);
    CmdRadGrad s;
    s.index = raw0;
    s.mat = vec4(uintBitsToFloat(raw1), uintBitsToFloat(raw2), uintBitsToFloat(raw3), uintBitsToFloat(raw4));
    s.xlat = vec2(uintBitsToFloat(raw5), uintBitsToFloat(raw6));
    s.c1 = vec2(uintBitsToFloat(raw7), uintBitsToFloat(raw8));
    s.ra = uintBitsToFloat(raw9);
    s.roff = uintBitsToFloat(raw10);
    return s;
}

void CmdRadGrad_write(Alloc a, CmdRadGradRef ref, CmdRadGrad s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, s.index);
    write_mem(a, ix + 1, floatBitsToUint(s.mat.x));
    write_mem(a, ix + 2, floatBitsToUint(s.mat.y));
    write_mem(a, ix + 3, floatBitsToUint(s.mat.z));
    write_mem(a, ix + 4, floatBitsToUint(s.mat.w));
    write_mem(a, ix + 5, floatBitsToUint(s.xlat.x));
    write_mem(a, ix + 6, floatBitsToUint(s.xlat.y));
    write_mem(a, ix + 7, floatBitsToUint(s.c1.x));
    write_mem(a, ix + 8, floatBitsToUint(s.c1.y));
    write_mem(a, ix + 9, floatBitsToUint(s.ra));
    write_mem(a, ix + 10, floatBitsToUint(s.roff));
}

CmdImage CmdImage_read(Alloc a, CmdImageRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    uint raw1 = read_mem(a, ix + 1);
    CmdImage s;
    s.index = raw0;
    s.offset = ivec2(int(raw1 << 16) >> 16, int(raw1) >> 16);
    return s;
}

void CmdImage_write(Alloc a, CmdImageRef ref, CmdImage s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, s.index);
    write_mem(a, ix + 1, (uint(s.offset.x) & 0xffff) | (uint(s.offset.y) << 16));
}

CmdAlpha CmdAlpha_read(Alloc a, CmdAlphaRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    CmdAlpha s;
    s.alpha = uintBitsToFloat(raw0);
    return s;
}

void CmdAlpha_write(Alloc a, CmdAlphaRef ref, CmdAlpha s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, floatBitsToUint(s.alpha));
}

CmdEndClip CmdEndClip_read(Alloc a, CmdEndClipRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    CmdEndClip s;
    s.blend = raw0;
    return s;
}

void CmdEndClip_write(Alloc a, CmdEndClipRef ref, CmdEndClip s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, s.blend);
}

CmdJump CmdJump_read(Alloc a, CmdJumpRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    CmdJump s;
    s.new_ref = raw0;
    return s;
}

void CmdJump_write(Alloc a, CmdJumpRef ref, CmdJump s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, s.new_ref);
}

CmdTag Cmd_tag(Alloc a, CmdRef ref) {
    uint tag_and_flags = read_mem(a, ref.offset >> 2);
    return CmdTag(tag_and_flags & 0xffff, tag_and_flags >> 16);
}

CmdFill Cmd_Fill_read(Alloc a, CmdRef ref) {
    return CmdFill_read(a, CmdFillRef(ref.offset + 4));
}

CmdStroke Cmd_Stroke_read(Alloc a, CmdRef ref) {
    return CmdStroke_read(a, CmdStrokeRef(ref.offset + 4));
}

CmdAlpha Cmd_Alpha_read(Alloc a, CmdRef ref) {
    return CmdAlpha_read(a, CmdAlphaRef(ref.offset + 4));
}

CmdColor Cmd_Color_read(Alloc a, CmdRef ref) {
    return CmdColor_read(a, CmdColorRef(ref.offset + 4));
}

CmdLinGrad Cmd_LinGrad_read(Alloc a, CmdRef ref) {
    return CmdLinGrad_read(a, CmdLinGradRef(ref.offset + 4));
}

CmdRadGrad Cmd_RadGrad_read(Alloc a, CmdRef ref) {
    return CmdRadGrad_read(a, CmdRadGradRef(ref.offset + 4));
}

CmdImage Cmd_Image_read(Alloc a, CmdRef ref) {
    return CmdImage_read(a, CmdImageRef(ref.offset + 4));
}

CmdEndClip Cmd_EndClip_read(Alloc a, CmdRef ref) {
    return CmdEndClip_read(a, CmdEndClipRef(ref.offset + 4));
}

CmdJump Cmd_Jump_read(Alloc a, CmdRef ref) {
    return CmdJump_read(a, CmdJumpRef(ref.offset + 4));
}

void Cmd_End_write(Alloc a, CmdRef ref) {
    write_mem(a, ref.offset >> 2, Cmd_End);
}

void Cmd_Fill_write(Alloc a, CmdRef ref, CmdFill s) {
    write_mem(a, ref.offset >> 2, Cmd_Fill);
    CmdFill_write(a, CmdFillRef(ref.offset + 4), s);
}

void Cmd_Stroke_write(Alloc a, CmdRef ref, CmdStroke s) {
    write_mem(a, ref.offset >> 2, Cmd_Stroke);
    CmdStroke_write(a, CmdStrokeRef(ref.offset + 4), s);
}

void Cmd_Solid_write(Alloc a, CmdRef ref) {
    write_mem(a, ref.offset >> 2, Cmd_Solid);
}

void Cmd_Alpha_write(Alloc a, CmdRef ref, CmdAlpha s) {
    write_mem(a, ref.offset >> 2, Cmd_Alpha);
    CmdAlpha_write(a, CmdAlphaRef(ref.offset + 4), s);
}

void Cmd_Color_write(Alloc a, CmdRef ref, CmdColor s) {
    write_mem(a, ref.offset >> 2, Cmd_Color);
    CmdColor_write(a, CmdColorRef(ref.offset + 4), s);
}

void Cmd_LinGrad_write(Alloc a, CmdRef ref, CmdLinGrad s) {
    write_mem(a, ref.offset >> 2, Cmd_LinGrad);
    CmdLinGrad_write(a, CmdLinGradRef(ref.offset + 4), s);
}

void Cmd_RadGrad_write(Alloc a, CmdRef ref, CmdRadGrad s) {
    write_mem(a, ref.offset >> 2, Cmd_RadGrad);
    CmdRadGrad_write(a, CmdRadGradRef(ref.offset + 4), s);
}

void Cmd_Image_write(Alloc a, CmdRef ref, CmdImage s) {
    write_mem(a, ref.offset >> 2, Cmd_Image);
    CmdImage_write(a, CmdImageRef(ref.offset + 4), s);
}

void Cmd_BeginClip_write(Alloc a, CmdRef ref) {
    write_mem(a, ref.offset >> 2, Cmd_BeginClip);
}

void Cmd_EndClip_write(Alloc a, CmdRef ref, CmdEndClip s) {
    write_mem(a, ref.offset >> 2, Cmd_EndClip);
    CmdEndClip_write(a, CmdEndClipRef(ref.offset + 4), s);
}

void Cmd_Jump_write(Alloc a, CmdRef ref, CmdJump s) {
    write_mem(a, ref.offset >> 2, Cmd_Jump);
    CmdJump_write(a, CmdJumpRef(ref.offset + 4), s);
}

