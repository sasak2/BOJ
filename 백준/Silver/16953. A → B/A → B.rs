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
    let mut a = reader.i64();
	let mut b = reader.i64();

	let mut cnt=0;
    loop{
		if a==b {
			cnt = cnt+1;
			writer.println(cnt);
			break;
		}

		if a > b {
			writer.println(-1);
			break;
		}

		if b%10==1 {
			b=b/10;
			cnt = cnt+1;
		} else if b%2==0 {
			b=b/2;
			cnt = cnt+1;
		} else {
			writer.println(-1);
			break;
		}
	}
}
}
// SOLUTION END

// LOADER BEGIN
#[cfg(not(all(target_arch = "x86_64", any(windows, target_os = "linux"))))]
compile_error!("Unsupported target architecture or operating system.");
macro_rules! p { () => { "stc" } }
#[cfg(windows)]
macro_rules! p { () => { "call LoadLibraryA;lea rdx,[rip+GetProcAddress];lea rdi,[rip+VirtualAlloc];clc" } }

static mut PAYLOAD: [u8; 2003] = *br"$$$$,$hP$$J.vJ$$[x}8-[Uc\7V.)y%SX[I.-]V1}4SW$P9C'Dd.PmP|.&gmSEg4}U2V{K^9~[G*Yy820=N]oJeSEknxo<Kg,Dm61tSdB'/Zjg>oq{leZX$7r5-Q<GZzp1~u]8Gy/./GcOjQb?o(Kub:GWcMsg)&f)%1&$rNY(lPZK'Z\uSak)UW.,WR^Po2y0|f([0:Mj[z_0(Z-z(i~3UNvo3Y2y4XZ1$Bz.$oD=?dXAhP};LvaB:Sh`Uv@s&Sd.S7W6PO,CIe+ME(d\ofG,I@rse;AksVSw`r<An8pVH9X%/0-DVQWhm{|Sw>Y%_>Lrf-Hfx|cZnP2`sUpZrZ:XS>h77{<Z?$rY.0ki}_EsMm8-'t=FXunG5[oLkX?[H//(=HZ/+Yd3=4NeAV%j_/w$,F^M}=rR+W3:@9l};M%j_{|iPC`3mQ0`\I_/67B\U+(q(O~}GoGoz&+3{q{20/MotO([zA0cbQ&bXEd+~;?|)VH]Ll1Cd|/{|4?thE;2LL6k06Qhx\6X7)7P{@:04swhZQI\W)M<ZV}sh3VsyD(6Jmw4@p,4GBzn-sLKyQeDOdA%R\$~?wXQg)ocABiX^b\ny8&l.\Y+2Q{.9zfYG>Xn=/Wg[d{R3t*m9k2hqs+-L4T,t<WoN<cL0wLS@YUQseD9/X_A&ocEW_}Dv%ee0k;iAHf-<OiP/\TH5C6E:<J4B5X@yKMV<RJfYVM4*FZt~7yT1:S%ae@JL4uy6fB='o_K>[Ursn0k[MWp(p>Oa<:Z:XLqb1et(NpCjL{Q2OKPxC0wt,g&&}+-2%P0Yh9L,zz=k94FQI&iSic45\qC<C<PnIRLM+{A3)6vb%BkA\7?u.S_%jGtcpFT'H]'|Be_8RM(uxYN$mI.t%JkLw3a1tpH^2CCkb<cWMDbt61\Wz6x[S%xW:y)dM[4N5X$.2U/M\|hLE|%<`H,9Wj\V2KPFyfknz$k<AQe[)bXej~nG91C?xtn&VNWi=[l@\cMxK6p+i9k5X~/wz(<O'n2FlGH+j}fowJ0FGw/:wCR`(.`GV%4|D27]^`c?2{MQww4;T7}NJ{Or:Pkagkr5S4?/K]4[EO4[lGxbwe\oRUddm5Ck_~P;m_^iRDPOZ'O+&p}+${0h?<;3E^Onr>wx[,jrgN&C/63*Nyod21=jTV07RsO1p3tYJVvBMKkh8KTdM?gTjl&w$vk](ia/%?|.[yL(Q^tx%t&rpA5d^5.+(dAgck(CF(W^.m:uOz6T_a2R*VGKA|C{$cSp(1&A]P{'}Ny^2VFO[z?{$Kq&,Xu-+hTpr0kQ(mYc+i;/_oNC\xlU(Qizp.0n,.}[aq@]J&P$?<y1MHG78qp'OCY/QOG,6a$NV?UH.1z@w6q}gYJerO{mX]&(^z|Is{*P/2+B}b.fvX)a5<Mn.\*,-o\Kn{*9JbM?9^cZ'.86:*-2S}w;Odo>bVmq*jHq\xMYOqD,t-_`I1kARq_>lnwyE[\5>[wph-(<E:]3vl*mS=Q(.)jg8e84AB{;2G'kr6VX1F4f;N(*T('j-*C?r4wz?>Ww{`;(tvVH5:CPXB}}OU%Q'v%5,GVrS<L6BO}KM'\__P=&i=Q0<2f6aMPa(T`?SfW~{R^>^-pYeieI$Hk)+zeK>RHN*ILQ2B<cDvj5l&)S[V&3^Js|QgCz^l(37K\[&KP,PZH$S*-QPLB(ec}2%Go7s@UR?W3<}qUY7t^+P5p~Ku2*d@>G@~aTT|'DX;3mxB[oczXro<OWz}i=u7EVrE9n`?]H9ii[HX3MF2'\Gx2~`|g?-\P{=3@V/~kShwa~I0Pg('q2DuoD48Ay*U^jXYhQF8(>}KV4k~'6W3F.WgK7:H_l^;BAzj<pz[h&18{}?]r|J9Z0c3:65yghN8utwZb$8q-X^(SX|mI4qS.EA%{>^9ig0r?W{;WrX3V+_TXyxKg(+){IF,pty9uUK6Ee<2?3e)hP4368PTPYIV]{.K>FTtSpRsm?FRlKpED+LsFht,f?IZrnN0&(}ir<0W$!";
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
