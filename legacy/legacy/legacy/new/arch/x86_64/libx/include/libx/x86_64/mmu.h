#ifndef LIBX_X86_MMU_H
#define LIBX_X86_MMU_H

#include <libx/defs.h>
#include "cpu.h" // TODO: remove it
#include "misc.h" // TODO: remove it

typedef u32 x86_mmu_pd_entry;
typedef u32 x86_mmu_pt_entry;
struct x86_mmu_pd;
struct x86_mmu_pd_entry;
struct x86_mmu_pt;
struct x86_mmu_pt_entry;

typedef u32 x86_mmu_pd_pse_entry;
struct x86_mmu_pd_pse;
struct x86_mmu_pd_pse_entry;

typedef u64 x86_mmu_pdpt_entry;
typedef u64 x86_mmu_pd_pae_entry;
typedef u64 x86_mmu_pd_pse_pae_entry;
typedef u64 x86_mmu_pt_pae_entry;
struct x86_mmu_pdpt;
struct x86_mmu_pdpt_entry;
struct x86_mmu_pd_pae;
struct x86_mmu_pd_pae_entry;
struct x86_mmu_pd_pse_pae;
struct x86_mmu_pd_pse_pae_entry;
struct x86_mmu_pt_pae;
struct x86_mmu_pt_pae_entry;

#include <libx/types.h>

struct x86_mmu_pd
{
    x86_mmu_pd_entry entries[1024];
} ATTRIBUTE_PACKED;

struct x86_mmu_pd_entry
{
    u32 p: 1; // present
    u32 rw: 1; // read/write
    u32 us: 1; // user/supervisor
    u32 pwt: 1; // write-through
    u32 pcd: 1; // cache disable
    u32 a: 1; // accessed
    u32 avl_1: 1; // available
    u32 ps: 1; // page size (0)
    u32 avl_2: 4; // available
    u32 address: 20; // bits 31-12 of address
} ATTRIBUTE_PACKED;

struct x86_mmu_pt
{
    x86_mmu_pt_entry entries[1024];
} ATTRIBUTE_PACKED;

struct x86_mmu_pt_entry
{
    u32 p: 1; // present
    u32 rw: 1; // read/write
    u32 us: 1; // user/supervisor
    u32 pwt: 1; // write-through
    u32 pcd: 1; // cache disable
    u32 a: 1; // accessed
    u32 d: 1; // dirty
    u32 pat: 1; // page attribute table
    u32 g: 1; // global
    u32 avl: 3; // available
    u32 address: 20;
} ATTRIBUTE_PACKED;

struct x86_mmu_pd_pse
{
    x86_mmu_pd_pse_entry entries[1024];
} ATTRIBUTE_PACKED;

struct x86_mmu_pd_pse_entry
{
    u32 p: 1; // present
    u32 rw: 1; // read/write
    u32 us: 1; // user/supervisor
    u32 pwt: 1; // write-through
    u32 pcd: 1; // cache disable
    u32 a: 1; // accessed
    u32 d: 1; // dirty
    u32 ps: 1; // page size (1)
    u32 avl: 3; // available
    u32 address_1: 8; // bits 39-32 of address
    u32 rsvd: 1; // (0)
    u32 address_2: 10; // bits 31-22 of address
} ATTRIBUTE_PACKED;

struct x86_mmu_pdpt
{
    x86_mmu_pdpt_entry entries[4];
} ATTRIBUTE_PACKED;

struct x86_mmu_pdpt_entry
{
    // TODO: do it
} ATTRIBUTE_PACKED;

struct x86_mmu_pd_pae
{
    x86_mmu_pd_pae_entry entries[512];
} ATTRIBUTE_PACKED;

struct x86_mmu_pd_pae_entry
{
    // TODO: do it
} ATTRIBUTE_PACKED;

struct x86_mmu_pd_pse_pae
{
    x86_mmu_pd_pse_pae_entry entries[512];
} ATTRIBUTE_PACKED;

struct x86_mmu_pd_pse_pae_entry
{
    // TODO: do it
} ATTRIBUTE_PACKED;

struct x86_mmu_pt_pae
{
    x86_mmu_pt_pae_entry entries[512];
} ATTRIBUTE_PACKED;

struct x86_mmu_pt_pae_entry
{
    // TODO: do it
} ATTRIBUTE_PACKED;

#endif // LIBX_X86_MMU_H
