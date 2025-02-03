#![no_mangle]

use core::ffi::c_char;

extern "C" {

}

pub struct FilesystemInterface {
    pub file_create: fn(s: *const c_char) -> f64,
}

fn кукуёпт(i: FilesystemInterface) {
    (i.file_create)("qwd".as_ptr().cast());
}
