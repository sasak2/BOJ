// Generated with https://github.com/kiwiyou/basm-rs
// Learn rust (https://doc.rust-lang.org/book/) and get high performance out of the box!

#![crate_type = "cdylib"] // On Windows, omit this or pass '--crate-type=bin' to rustc to avoid DLL creation.
#![cfg_attr(not(windows), no_std)]#![allow(unused)]#[no_link]extern crate std as s;

// SOLUTION BEGIN
#[cfg(any())] mod solution {
use basm::platform::io::{Reader, Writer, Print};
pub fn main() {
    let mut reader: Reader = Default::default();
    let mut writer: Writer = Default::default();
    let a = reader.i64();
    let b = reader.i64();
    writer.println(a + b);
}
}
// SOLUTION END

// LOADER BEGIN
#[cfg(not(all(target_arch = "x86_64", any(windows, target_os = "linux"))))]
compile_error!("Unsupported target architecture or operating system.");
macro_rules! p { () => { "stc" } }
#[cfg(windows)]
macro_rules! p { () => { "call LoadLibraryA;lea rdx,[rip+GetProcAddress];lea rdi,[rip+VirtualAlloc];clc" } }

static mut PAYLOAD: [u8; 2027] = *br"$$$$,$+O$$J.vJ$$[x}8-[Uc\7V.)yGMl]gOSpNz*-gbJ+R'9muo;:9n4[adV\U}}8:qM[g/d&&'nrg8{HY,>?IgW[4.*haq)CLp,@hP]p[G-vb2Yij[m:ichP:Hk{W+e[?(1M^ksE=qFBj>:B8:?^)X3rk?ubi,6XP'r++i/SiVhJ3u1GxqT/m5ILzL'+Tev/x)/Z@Shk\}830dz{g7o-5O53-LHfHU|b])J4-WU4vVKp|]L:Sj&bFY3]0tK)l%&)WbZ6<=x%`.C=w^M/0^6l3F?PY].H9e6|~e'f_AORMZfmP4A8h;p-HNX>nwLl{^^xZ[|.`.eyPJN0yP/m<Tvng4?.9tL8[Wj0Bfu\mer7_W,M:}1qy07h49x0lZTNC-MlWFux63mQCGtc56.-\:J^^tAw|BfNl+NM|SEr;W|H<JlpN:BeO4M5IC:`wrJw\@M<W@KC4BZtWa=4{mldPfbAVNI*|0,y$DW1*PX8ha6tcz4Z,=?6gtR_)M4.GTm(l]jh0gL6shhSP/SEwsw$:m}Fe-yRYCIc,n41='WnI][Fn(RE=3xo*S6W.Hfpu8\ROvt%m;>W)kk??Ct.BWj//b*gEuc(7`5h7+TkewyBMQDs/03E8AyATbreNufr>2XHZxd9O4Q{<r],1U`QGE01IVvj0;v@-%Hj9Dy,KC4Sm`'%|Xe})lArBM8dBZoj6$C%D*LTljJF5\%vfm%Sm+waVBmuN+,]T6iPomi<8i6,*RNqHbl%9z<D@BcH^vr`>,~lH>Q)C>*lJC]D}\|Vmq{yXgDeD5SL`_@6Nzrm{(::/2,]kjE9$FSc6(\$Pqpiban3mZaZWF;S)b'Y.nBSaxl{a{YPG/Ccc`LG43%f7TXFySxO3Tp\M@s;7KSTI1|KGQ9J6FYkMnk3xL=z4dDe~spJ`4G*uA-<o?pz{<=`l&QXu5&M'vV*y80d-T;cq&;+.P.54j&z~Tr]p,Y<*4pF~)je|/3IuQM)bew0q%~xE9Tuzc{pE^c'f$g6K*2is<3+Qx?m-%:@z>g0K`XiA:}Sv8V[)oP;PWG.S.B6TmZg}5R4|b..>4x^]kF{p,piI'I67F_l$MAbjt68Njr)*(f.$0J-k7VSgqAh,K3]Tft<hY:_Fk\2bALo&==j=_mR_Bz:fI+b5[dHp/A{dh;yZGdS8E-Hyn]{lW-uj;E7~S,q`P-TY&pVzk7FM9~xGMuJ5_~<%?vj(dK-4y>H{'F}sNJFxiI]lIR'}ll&Umd4..*{.<je4^%'~3QKZTnOl:7:GL:s79&>[ST{*@ZEcwqJ.J?lcBfZlQ[ohOYp~Kn]E>7Wu4:SxQ+)R4Hu%/)^OGdu/ArOdfI8fr({xWoZg_Ra_K;t9MqyUSf]77CsVI4$tibljPoO^$QESIY@lQ_oeUtj`\MWP5U&74{_aO])<4]p(23-bu+i\K>ZSGE>wHYhHj]oe+|jdx6b]5H(]8l]F;$(|QVym+Ip0E=YEW^1YQlETxy2`T<yXs96r<HNgY,9eIRi<qQMQVbLm052z%rD&U.)q0*y>UQTTL.rZO^PcC\s7=,YxoZxd4hd_`hYQ]0dxO+jM[&iPfb;{dw9Y6\py-,6g3^z4+Zg;wVkk`C7AJGRC$'1\dZn4_L1~C4iuc27MP[sG};%+9/OR/kQ]&\@g[o3c@JFO3G[.?yDHL5NXe?CmO+M|7s3b<W|$e*F0Zc_f8y_zA<;7TkhYKdMIp~Y3jM]j7X\eEChW1>eanO*S@XKngBD0Y~G[zd{/JeCEu]]G`Gp}mDETF%+vbz<8o}jQi\4[+dj,f1F9zm@&5?,+U\n1WJdC2(.|.qEKwgoWmKuT7@_+hY>A?5fyC|(/{0+JPi@_bd]$vv(g(i%=DZ_6L5=&oZ4}.p3^Qx@o-'czK?:op){|2BKP|Vg`$\rZ}S1ff@^e'{-7pN7{59Ty*:Z3GHnD-(\o?]lDlw/&W>m>fd)S0AudF7y:/`G~7-adifJ%>*G^X4-|t;2W>N-5P[UT7kqVS8E`x:B)ILeaAI$w*<ge-T41IGx0)%l!";
#[no_mangle]
unsafe fn _start() {
    s::arch::asm!(p!(),
        ".quad 19510173000030c8h,4ce8d9f7c9h,459927e36758096ah,870d74ff8548c931h,\
        4100003000b841cah,0b2ce8956e7ff40b1h,41ff6a5a41226a07h,0c11fb0c35e050f58h,\
        99f572242cac0de0h,15bc06b242cac92h,10c4f608e8c1aad0h,5052535be3ebf775h,\
        20ec834851c1ff51h,0c93197485750d3ffh,90c9d0ff585fd3ffh",
        in("rcx") "KERNEL32\0".as_ptr(), in("r14") PAYLOAD.as_mut_ptr(), in("rsi") r"-n[b4n2|3|z+6|EI_'v:ZWHZ}\DWh'i'j'd<^V^VrTubU$7?Y`xGcbG67?Y`zGA(ocPYN&)$,$;/*]fU\)w$1]]T8?j]Td~_hpAtUmVHd/T8d/*>Va^h7{]uV7R+'_N-pX@=MRg+uQ^8F|CZWSm$0@^VyMR:$$sd;;>%g|50;BcHEN[?<ko?F-$\M=MhA)L;tO@'Zg$$]<GjL>o_Hxrois1&*9%QaL[']h%=9hS%%|hXW3~.ns2>N1;;1=oXxbVNMeb=^iZ4n]V8w{cl-A06{{pki.9^XHQq%Q,$])cn</advVEQ--TY'm_sbV5Qo(Z3OgQe5)DW''DTL&UVFdvyE$3);)2dRg0pT]xlW&q&$$i0:Kv*s7Fj,TE1(Q:/$YBNG{jQ?@;29YoT8Yb7hE$Y0p$[8{FSN|%JY}J=a<$$^V4m.w}}*dyB;t,`v^LxRguWe|lsoLEhfVL(n]^l$QX}b<At,V'$,Uj(irn[8@zy8U|4*+x.&/UA^)xbi'A7RgrTvPFdK6vb4/GR]1LZ't_-=h*:GDya=$m,zy2n0]OIemm&5V]?R}i>H8uWL-4/bV)>_}\?T}T}-dAS]+2m{h\7N|U{e<of$~]V|sME<kplL;YkG=L;WxoD{h~1f-6ii'W}s<rTIgFdR=g.caW)<7\)69\s9q]W-J==DY6)4Qjtw&0XZ=\)hEVlDuAH$~XuGID0`@DkPh:-9hcd[?x{C*q'`WPsHy(%1&!".as_ptr()
    )
}
fn main() { unsafe { _start() } }
// LOADER END
