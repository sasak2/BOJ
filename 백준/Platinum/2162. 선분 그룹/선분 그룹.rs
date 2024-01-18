// Generated with https://github.com/kiwiyou/basm-rs
// Learn rust (https://doc.rust-lang.org/book/) and get high performance out of the box!

#![crate_type = "cdylib"] // On Windows, omit this or pass '--crate-type=bin' to rustc to avoid DLL creation.
#![cfg_attr(not(windows), no_std)]#![allow(unused)]#[no_link]extern crate std as s;

// SOLUTION BEGIN
#[cfg(any())] mod solution {
use basm::platform::io::{Reader, Writer, Print, self};
use alloc::{vec, vec::Vec, collections::VecDeque};
use basm_std::collections::*;
use crate::alloc::string::ToString;
use crate::alloc::string::*;
static MOD:i64 = 1000000007;

type I = i128;
type P = [I; 2];
type L = [P; 2];

fn scale(s: I, a: P) -> P { a.map(|x| x * s) }
fn add(a: P, b: P) -> P { [a[0] + b[0], a[1] + b[1]] }
fn sub(a: P, b: P) -> P { [a[0] - b[0], a[1] - b[1]] }
fn dot(a: P, b: P) -> I { a[0] * b[0] + a[1] * b[1] }
fn cross(a: P, b: P) -> I { a[0] * b[1] - a[1] * b[0] }
fn ccw(a: P, b: P, c: P) -> I { cross(sub(b, a), sub(c, b)) }
//https://bamgoesn.github.io/rust-ps-md/geometry/2dgeometrybase.html 밤고수 템플릿 뺏어쓰기 hehe
/*
11049 행 곱 순

dp i j = i to j 까지 곱했을때 최소 순서

i~k, k+1~j곱하기
k= i~j;

#[derive(Clone)]
#[derive(Copy)]
*/


fn is_GyoCha(l1:L,l2:L)->bool {
//https://killerwhale0917.tistory.com/6
    let mut p1=l1[0];
    let mut p2=l1[1];
    let mut p3=l2[0];
    let mut p4=l2[1];
    let temp:i64=0;

    let p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    let p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);


    if p1==p3||p2==p4||p1==p4||p2==p3 {
        return true;
    }
    if p1p2 == 0 && p3p4 == 0 {
    	if p1 > p2 {
            let temp=p1;
             p1=p2;
             p2=temp;
        }
        if p3 > p4 {
            let temp=p3;
             p3=p4;
             p4=temp;
        }

        return p3 <= p2 && p1 <= p4;
    }

    return p1p2 <= 0 && p3p4 <= 0;
}

pub fn main() {
    let mut rin: Reader = Default::default();
    let mut rout: Writer = Default::default();
    let endl="\n";

    let n = rin.i32();
    let mut arr:Vec<L>=Vec::new();
    let mut unf:UnionFind=UnionFind::new();
    let mut cnt:Vec<i32>=Vec::new();

    unf.resize(n as usize);
    cnt.resize(n as usize, 0) ;
    for _ in 0..n {
        let a=rin.i64() as i128;
        let b=rin.i64() as i128;
        let c=rin.i64() as i128;
        let d=rin.i64() as i128;
        arr.push([[a,b],[c,d]]);
    }

    for i in 0..n {
        for k in (i+1)..n {
            let l1=arr[i as usize];
            let l2=arr[k as usize];

            if is_GyoCha(l1, l2) {
              //  rout.i32(i); rout.str(" ");   rout.i32(k);  rout.str(endl);
                let a=unf.root(i as usize);
                let b=unf.root(k as usize);
                unf.join(a,b);

               /*  for i in 0..n as usize {
                    rout.usize(unf.root(i));
                    rout.str(" ");
                }
                rout.str(endl);*/

            }
        }
    }


    let mut cnts:i32=0;

    for i in 0..n as usize {
        let temp=unf.root(i);

        if cnt[temp]==0 {
            cnts+=1
        }

        cnt[temp]+=1;
    }
    rout.i32(cnts);
    rout.str(endl);

    let mut max_=1;
    for i in 0..n as usize {
        if max_<cnt[i] {
            max_=cnt[i];
        }
    }
    rout.i32(max_);

}
}
// SOLUTION END

// LOADER BEGIN
#[cfg(not(all(target_arch = "x86_64", any(windows, target_os = "linux"))))]
compile_error!("Unsupported target architecture or operating system.");
macro_rules! p { () => { "stc" } }
#[cfg(windows)]
macro_rules! p { () => { "call LoadLibraryA;lea rdx,[rip+GetProcAddress];lea rdi,[rip+VirtualAlloc];clc" } }

static mut PAYLOAD: [u8; 10021] = *br"%Q$$e){_$$NYJNddR1agi6Tv&P^>i&3jCk%QtSqYJ_\bTU>&C^nL*$,lA=S]vy}C5W>q3?puLM:4$k;uXn&|t4M*m?_BQ=y[dqj`^9kk<i)*xpccgwiFwAjH4,*IyNYvi=xWJT,SDwi$dn9.L-S?So&3hcH0y9;E*{MJ}[5|%`[(6O~J\9`a(]5>}A'}(tuce+-;.@5Pgw?ly:`Q{]3c?Nite<?Jq\tcJ+~cPAB,ZP(rm_$7PPdrF)<y=6FyW&>4\F`M4,q'mGg9tf34^ObKss(B/3wkAm}(dmS_&FEMrwp:RRo=,lx\?:7%\_xJ`kZF1P7{'DXz=u/gbB.\|+DQh)Gj:OZPr%R<0zZJf`@T^itPkdBbY%q.|$zVu]>VgE1dI8|>lc{8%rT^-hR2TO\gF{NeX+<0xE>ZkRf;id1\lw_+8<n/32d[k]<1S&5\6yvT@v3D{&`G?hSZ'l8B,(ZQKt6[Xjd+o,Bs7Au67xUshG6JOohf-kzFKWUG$Y>IL*b%Q9Iz5/Sub0ghXYLPu]_WDBH,\OoktCm@?BP=.l8R/j>dVZ]wF)@;sr)jyx~@4{$badUsc0Sy=Ab*hHwmRN1pw9}Yr|d9Mu0*6K@I5;}mDam*sc7zURa\24Gcm|=fxC,b-e`.8nS-+t/{GHN)qd.jUo$akX(}lp1EGjNFA6@+);`3}Cn-T+9bJt/:i+4?bH58gX1nSTHEq[(0.Ht/f8EvzkS4=zBuUkt-7fxgt,x9_Chkg6-iP`\3eMMoxqL.3NBfbh0bN6'rbwxYOSDxR')jS7/AP2Zv$K]z=?MYzt\H$pkPERec,rT:^Z8lUz<w\T;t>|\Tjkkdhlsz^Jq4QcxmBrul6|w{HrszX31(o=fb2@lJbj[TAxRU0g,AFE/;F|_IcZL@&W3a}%Q=FNGr}Zdlo/zTOaR+6<6}:2uyZE&+d.%cx@Zd;9}hiE}f'5w89[@-W&->?`9\'tEWNUw[,V=cS5sgYM4uZdK(pH*9;i]>3inH%.F{~+\{9ap._x\>,YMolj=Qls,gdwJT@j]&|oAZnP__^PQ}i'kMCEQ|Md4f'E_<B}y2T(GZSryel4]jj4sHzkoiJvref]*J+'Z\n7FzfDmL.[M$rPf4[HbsbUw6F>A_+.*AWcl(HmU9n`IZYnV}Badrq`PAODK$*Jp^^Ro]GJ;?Wh$RJh|le(^Q.Dh[5'1lnhkc<pHa47j5wCv4&=W|I2X1pC58d+:t7U8bfn<^M:\\r`KoND_i-,pS4N8V=K]OkzQ7-Xaj9*J[1+PS=[hUzJQq*)<@DkjI[>v.~$:0'UK>qF(&C%POOq8W{SrbX2^Ctd;5a*JLLnR2:h0}&(j[{b|Tx|-l_]z11<v7y5<:.9I*1`]TB`9m@oVFqvHU6u52EA)lrquhJJ|^B-D9-d1sI;kM(%/O7:pXOny}xs(9Jc];:t@*[wC|NQ8ZqZd_hIhRDtn}x`Pa9$~Id(~m1|Z*[L<aG[35VoaImpPT8'87nY%[F2]WdW4%lAFX'BWbiVF=lzru(9[^:y&srQQNc/h%{nq\Ht;/pcHb*Qnd\m^`?}&|D[YZi]LM1hf.hLcSJ*Dk^3L)hPb`i5v}lP2L/oq*,a-}4e~WC4I3Dlw^8u%jx`d1xT,\B,T0;Ukp.jQ${y|8v*t/C+jlFB^DaoTOaqznDv`?.A|?jQhp.|P'8qyE}xMCyh:?7mIB+Zt9aZ&IwR<]^@vF%I~cU2?Sib5*flvG&^9r+JS9y/s9]z<}GHc=2',i&I/YjxI:g=={H;?|3C7f=,Y/6ix3{;rx|;2KbRC1+A|j9MvrbfnZsA]d@SFPjr92?K.4QS1%lELZHo=hlUZlL=@HaB,ezq\j$6^s~+KE&OP)|H7xxVg:W&+oJzfhdG}z3>aV*OHi8HN3&ho?Zrt6dWeCYiN`}X*cpu7X13]OfDav\VDeD*&PS>)W>;e8A3.9N7)w<s|3R^W[(0Ve&11{~FQc<Jt(21O/G+}xlyX{N:]UV?[Ro,4HE'o;*75|_UJ$q^8Jqc%m18LRm*OBEm8dG&o<xAP.d.p6p%`0M?xK9'8't-XUWJct)b|:&|}tfL?|;OmY6Et>q7z35yAjB}(9Gvf_}&m4g_.VR[M;6m}uMeHvn+7D$0jMdsfrAP?wk<5230&s>9lJ*+2j+Ze5-iuyTy^.Lkw)F.2_T9SglK?u@GeXjs)PQU8ZX]ZGllu$645C6OC&CBcPAf`p1=n2}J:}b;Ec[j0H%\$4.+&B*8,o@nB9&zS\0+Y;e3TV08I4\fRwCIdy8xg$va|>k?/C7gXBd[}$`,aoI&Zc3n`,0M8@UG$XDPg*]0/y<yQN?dz'GcC7I-wRRa{ho=xLz{T53J(fj_iIw}_A4/|KZ:rfVOy<8d3|?<Zc-*r10,MGEJ|p.$1{?c)pc^DM*rD=3%S&S?D>4[NK?_u6o<qe]-/]\*-N]AwmjCDV<KJn7=fegt>yM5w>IDy(Cy$G>PPh-f/SS/%/Iyl;}):?8<Gw~N*n|WqAX}d8$}XDb63;<TcTff)pt^DKO'86s0=5^NNw[$4iKc$u}AZeR{Ejn&]|qDS^S5,(8)REq1,e~Vw7F-WAmoqj>I1LPH5vy/<F:r0,Z[37=O$hmx0n<9@o>TUV`&jsB:(?o+1+sJMDyzJ-0u*kQ7}$:xT(@IV+i/x$}EP%9QU9UxIyMZJz^+Kh],\sMe^<;T.Vn2w-vao_FfEN7^:i>Ius{<X'Zf|oI\Ob]v+O/8\**mwU4@ip}:N19-:F(<771;9aEr$C@:mi5\bWj-FL2_qJ9A+F)^<6TdrS8?YD]1JV;'e&*T.ne;Cd7?>INd53*ulC4Z]M5|ZY4<pe2eV5NrdDwX;FtHlT]$5DwRPyCRm&Dju6Yn4p^,9/h^[{Sh*B5Rw[ban8,K:)%r+/eQ_BIHVJ>aHD]W<AcjA<z9}h|?}/LU9]/4U3(h&tW&vn@j'9{A<a8&STUomN;g.6}Dh=j%Waz;.hdL&Z)@_$yvDo4ocF'b{&VR<,p>DdABr_zGw>rfo,K$RX9S`y1'5Eh=r+mI6<v]LE3NYFL&1Lj>);7_gk.0KiNQf0nVZ)?_v{\b7fZ>5M;c%G781csd`h,8NP+hZ8raBqeS[S|L>kn+[{Hvxw+]?HGx3A&l78kJRVTbsvOD_peY%VlHL6g3|0>pk6,.qk2^1^Z,vH)<=;/jipQ-8X$IWt&)0_<S*U*Gn:Mmj}gt;6p3fe,06H9oOs~WCkW,)\No[ZcPw|cXtO;hVSLvuNagq'L$L]_}<XNj'uri6@6['WKT'\:I(JwtN,oW<.%2;(?aqk=ktxfGB>T.sW}Ixi,>BYjaGf,e17Bj2yQB$8IN)72`5dm0Kg>$AQ-8LuW[8P}9$D&lmQ8=?Qv}&U5ZsJ};,9h,:<Tm.?ziu:\CQ4$q>X'j@N+]M;g@v.vNk83W/7T}aqHS;TsW-)P}|8A:vqW9\<QAvs^bTDx)v}yZ`BZdU=F?S1W}vvd[FPm_ipqjGXH6U,t>kB%9n>zt<XA4YBV_wC~`cN2bp@SJz4',c)kn5_6H)qNSEq)4XDu@~3kKu.yX4AlVp3R4h|nNz5*Op{0.4R{YOKV*xbqgo@xIy;}oqtneZ_>1M96x:{e^O-|^R<^2'Bw=Md]gw@/sMn(+~|]m/3:{YvhA<dgALunvLPtT6S<+(?QC.@6Ht\o*/|`9DT/@7z}oYz@&*I}>Fys>x>6/YMa+0SI8IlSmlWCy3LDB8?`;esCIf>eBi?VGZ3'>pUh]`}-PHdw+%fD$Yx@NLaT3/6ZSGM-scM-j1ZQM@k?YcE1ejWNoaTsNUu8pK%8j50*]:g0<?/rc]>q-6aGaNNxc$D<)H,}8fGm;_-@|0h%J=A_c=ikLXoijx|v8\mO.-}*f40yIUFHluP0aQgq7/_K+8FO-,v)b`SE'QbR>^I)FVj2yi3vzej?ji36W-aDjHhC8W,+x;Yop(m'ylJb$?0yJhW11eT6v0\Du\,UI@q'LQ8gF\Rz/=yy,R/V/j%CwFBG>\bU(@[]<rX-=yt&B2Fi=39&&fsB=fESCiJa_$vCXlKt4WFWC)4LfsuR/_S:t,Lgxb8e+Khx4nH\sf_@g1i2=zoJ|+3-vO]hLUzZ>qVU_MDtAS,3wV2MCYBs?}6-/*'jrj/4@c{U4<x&'YlWr&,%23[CQ$m?CCjqe~\|%65I9WUulhK5WPEl2@X7;'.U<_2?T?EvU*{msX0}I&{SdB<vg\-?fNG?;=1?eI%{rj5;@nD2x|,cyzeB(904BjB,^B;%ayje/xqt)~R~fshy2xYzQjm|;W`YT*_VAhWibgnBk]LFrLxY]Y>JY>/F2ZvP{g\+9JoPfjvgLhlp>|{\<.9yFPUQxc^u3'X]00=o)<vc(liHglOzC=xAUh_'9^P1P4&%7)1dxSM9(@HDrMbc9pe/P)jPD^pn1l;UA0J`/[|&HL*q2<K%|0;q@GP']fJ4t2;fK)&pHn7Cw4J`7OE';pC{W%qL<YJ5MICr7uk6KPRW&P?HJ&I5Nn2e9bB)j~_^&oc+DR6a+j[V_*$-sAcw*UY{&/_gT3liD\MaG_O:fTD|H{fa.&1;ckCV6,UC.DqlJ.SrsE?^\|aZc2`wZ~zQ=a5A.\[[$0ogg?dWD}j=}nbJ1sO)l%[4%|ZC9-?V%K*S2H&\T5t-3>-_Q0\;e1nMG+7s9WCcD3>AHvw^wWv6=co11@X&tV:<dK9w2Cpz7kc'k4jhSkQz4uX|^`zgHBX*tr/suw&meIuc@S-+RS6XnB@v;Gxwd:%0&Mv7K|z['E6O(a[nJ'N0jAf?A3rM6BW4*a<(b;}.*Tm(4&&r@YDxTPhNOP7-Nn[Iq\)d72lgb<e1q{`$kVtJ>uqOwCXUtY-aW39~4Oi'-s`Tq/bGuo)S(fwJ@0Lo85R{Ea-(qSoD`mk8||<&[w9T1-:>N9uE(<5A}uV~%IGm}9uKIAt]<U|/)>dPrai9'RZov%TZNKd~Kr>06k2U@RS|NMcy4EAjz;^[bt7<D[.C*uPxmoR0UxD[%%bU,\afDIXqJ0`@FGz[+_odj?d*ZU)fk}%=&8{a3=u@zH$N<BZ/_|)7s7s>kmuy``'\OH\E-xTg5-)ZUTc5-@8E]R>oq8X|Ii?;t:qFe6/t6*(oEo54mQ73KS^m_itJAG}3(9*jkl[o>{ETM0<Si6W[G1Tc4E8n[:^}CrkX=+Nej'836Q[(W4Oc==w4{T\L9,N7^D2.%CWZHm)9r(r~<bv<+*:a_+,(<P4rrNUYxS-MngaYr=9K(vVtfkzTys<c,**Rn}26iZ'3,,4]}('~%$&PX.r.kYI`6|VY9H=K.W)tfVypKC3Hp8qj6MBbJF(W1r,+D&0<g66?,$V_L/|F4{m1RqRLr}bwXcpcY]S^.|&0CZ_w:?1\0\sP0`%FHIv5eM@6n-/xKlM;1%TLR\{wZ9zAig=Aetp3&3[L3NEXctrH1:$NS$0FWOVdunP\T;RFc+3Y>^&2M.`qB,F+HI`Gu{uddjjrvYcE^K@N]xBIot+Hk|XVpE9}Nrf-FFR@fNZXMb[9'P:^Vj{Cqjg4Z0XC%/_=zZ6znMjD;?,gpBc(T{)&9BBD/P9e>w3@A~t+^})lCk(nu8:H'j5`8Q|V[9Gn$d;$@1qj`9^ZTzC0HIEWC5pXTkP9eoYTZ2vNa8?.CrK`e*}=O/\wZ*^/Xhk+$?dz\z?Xo`Q&'_q?W%MN4$=u]O\6X+lD;j-5(O+B]tQ\Osv^bG-S1M/6OiNWXGAjJ*Hr^yal3nC_%$Roi7R+sb*Da=Z5&5eg<j&-O@$&SF}pQMs*0S&VmFUnmlH7jn_kV/>zgKa0UuQ4}|eUXX90.~87S.(z'nRSGK&$l-6l'wS)FPymJa17027(Rn|43TWw=19TZ}s>G\@ZUR]0%d,lX|h_V2B.:~=SGs'>,&eu75k[v:j'PshFwZ=}eE;;dVu+[6jhdIP3pFYTj%BWYZ>QmVV4g=G{a'X[<7oft;Sd]OOZ9%$%mhx$]2q-nDKJY{&A0wHOx@'gh5Q[dx[/H<bif)P|0:OJ?+Qpo0u2C69EF)?CGj09;c9MvRUi/-J8-@HAVj_pg|$_Yui0rHsx7f&`YL+7=%/q=F0{<jg[9fdN\6a|_.61^N@>n0TA3}m<SoF,0Jv1xl?YZqz6Y^wZms69Ms+\,z]ffI;<`L[]-+}8JB2^Zkv]>s6FBF`+Mz+?9^sck[d.1sEPz|Rr;+IK+]xj}W@JFL5*Wlfg&<^u:K)*s]YfGS]+2E5360]hUCPZ7x'miU(gea9bLu9qPA,]?36?B^'rLKf?3s4Xq.od+3JR0Y*H';yLgx}ZcKO7?RHE(NKBh$5|k+N?R9Iv`FEx87fHs{T*ELn_@8@YK;J5loF[85H_NKzWe:/ewG.,`av_*HWRl]@*.I{cv\JqLgawpeWP>Tmz`V3e[W]^0(K\S,/F,f%McYocYev_TJ`PwIa7g~]P<k^NJ7\$Ok`?uhXdKLP7uH0zy=mN[uLR|x.=lXXi`Z.T56wGX@GkNm[s2iD'3q}BA*PlORRFmR-@K'0Q2%1GQzW$F&i:'_'6DO@p6F{+v%9/g\f5rKema]/loMr&gzZl9Cj%$7&r1HH(y)`Au<3C=~HYgT}jfD1$N/.|}CKFhDQc$S3S}}K{f^D9h8DxkX+Tl5XPwy{r=Q>(4=:?6xh5LtUlnW>@|c9VZjeoX\ltCTm5]Z>aL:2wv=_,r=4pyZLK\`LM'5;M065@@wc'k5V>gM;qZoZQ]d{@4iU.l(/L=+\5]'CY%)2e^sOSBKuk_kc3Cy+a%6x;lfKq9Bk;?~-nsL=HM]OFKWU,+swFy):Vb8>Az&7AL8^fkNGe>]>GJ(z1rBZq.j6LQy:8mN}tmRMT*9if;~58TjtXyRU*d(:1hJX{4ag}Vb,_|Ko`g0X&'_f*1F='1to'*bU|O>F1hmV%>,S^M]SY<8.6ryv-.gz.Jk'M%DU=-UMN\G,pdzd/sZ'jnwAIFuhK.ufQJp&SY*,hyEC/,'KHv5JK&n>2{(/fy[o7y*09a}7,Y{<d6n*m2n\*EH@}4iGBv=HOBS%h7F3g2=mL6GJr*Nn`rQGzg}l$%D9$AbVl6?Idt8OcLx?]N;K.X-3?F:0pxzC(rC[tvzPRi*^2O%;ai,`'n1>Fe=i=}GCON`^MYVrr3wZ+w_QBWoTGXnl6vS\>vnV=bxs~bp6m0tX6Oh9xHZ$DDy&/p73J{SD-?`Tnfsx(F'j.W,^=3s5yM.;?2w:,*CX<LeQ9FgQSsNt.]t+Zok13J*nn$<ho`5,ee3{Bns5+q~+)7~+C4QVDXjug[s+|j70^;szj.]h?l[U{FE_>\FIp=uWCR;?M,uAoesgfNB[:j>KeNWzM'9qLf4E%b7/3f^EFx^+&JI%E65Bsb:T|v`VaGIzWmM.ga$bJiXdAiNnTCs:R|3Y`$2SH\nfE3R?.S;->IT7Xn2&y`Y{T(rSZ@Pl,d8x-k[wyEC7@4'UllE7zi2BHGIKO=~u,QYHe[WWVk;'U_q)_9-too+dk88O6g%j0t>e>W6<IpvyIZNlqFx^4Rw{Pj4PT_1OUbComc0E};]b5I.K&H30g;dE'2zH:5n(1QEx~:eTQ3d94Zgs*1K}iZkv.(ZL<VnndN/*KNekRsn9qCpfqon)LLY|b_md'U*oU5-Q}.r--<NUkiHyAcA0c_&<e1^8bowL=ayK}yI;mkW'9crpw$b)CmV<Hog)gK5)C>`9q5f3SCUnMt}dKZ0Q<_oJ@{?HU/GE=X(Ks?s)yxlBgczgP)$,<c`'z3PAG9h<~d[Tr`+$JG{5oD2=;'`6|U]q4}(pV)[tem5ITknKLA26JC*a\BL':Tj'{lleF*$`xy`o_RHFvq+og`jY61tBHLohjbEm,SY'_NZ.kRlpI-XUTguLh'%j(4TtWVXmk<Rw42>m`40aCy{5rP6=V_g,*;xhrzsrxzXam3;>:?H;R|4jx0Tj6G(+)==(jjlb.--M&Oe^H05Qo<?=xZ`gSA3\oa[:vj/3}.?wjuM1).S5}bU-JLx`eo@'oR^Q<A5Z%9xhS=OW}%fsZ-<Xs_=&wV}OXE5eE^.6JQa`p{XL8XtZH}^W)vn\utt*%H5_]om4PV0n@^(=,:U@QEv;dD/w(.=BCq4?BPTi0nR9b\H-7>TYI[R;6*qlBo4N7,gqc7me6S5JQlTcAJ*O/?S/{Lgr82QOiSI1iQgvH*](1/5C.}{M,bUvid|'pg7Y&ankY28F:XgcXWL3$kY/YFL13lbZ'NpI(dpLLVKe.vsDq}x7w5kisUEp5e0$-%jxYM&RKXn=uR*%o,yKw/d,C?y3_xO01%PtT'I1c.qtANfP'4tH>DdLrP&VRH&YBwZzVE<*R-E){PjXI.Rqq9UbYM5*n<IJ+$Y78r}xI\b>x\VTRsQZV_~q/E\drkuN;FB:i_FW:|i*auHW}&`?>VG;.l+agEJVfG@fI|@Fq}k}a5:u~,DU?zSmUdh^|T/mHtbF8YjT;hX$)B4_0zp$xuQ{ot/K{SRT<d2kp[zkwJsPmCSBH'Axqu2D=fqZ94r?rcCK~t)kTYwO6FIDnGTe+&V@C^gX}W@uYlY4<A13V587O<msejh'1cfk343fz=6%Tv{/33;n%pGK%ydG-(Ps%3wcMvrs^g9lL]%4(/M/_tB}XEj&)7xpw;}=dT880-lpw*iaO>:MOW|d8:%{0wQ%7/dL6fs%=Q1Dgsk76h/Bh6-^m4Vo:r?qI{\Q%I(CHvvM<Mgp'X}NX@F.k;nuuL^Nds^/Y(@Fz:dgQ$Irj(s[6-u0ER|]*h7{rGxV4`M)@xrK\e2<;[aQfp)Fa^w`DGSdIz(hQXS-]($Fmu)Ju{9_7W<&V+`lei%+uy|-|N>:BbY_lhq}Z7OOhVIUA?j-HCFSX'D7(\mctf\u:<g(dykcG4UFHB=&eKy.P-4;?E7<go*Oo:jpBYH]k4vbm\IC+>c8PxD1@y9k8upg]B2|/,Z5f;w$LxMk_o:BX*^NNih)DuC6XXNoy<_w%k+zwn`yc>P;~x1c^QwM$Jt*s`J3=9i:Pn1(1<j`|fWQ&92@-$s&sGkMw),-RW4R7zl:KI`b+@mRXixXY=Z$e>=FWgFGz$'.z@t@z+6T?NT[*O`&AUyL%=PM%`Ali}[0N85)6s_>'U(tC75O$a.4,eUGu:Q1NYn;cBI8kntr/[vs[;2&/%bWkM,,&l>pskE$jg\yQ?;B/,M6G\bvaIwN{Hx\tShuwpq%*yn0IHc<V%{JAc,82)yQ4wn3J1qAeIRpMIlDxZm6.a;0$y)p8SZTL.$]1>6-AXeCf?\tt:GA8_Dq+O8*MMn(eoZ*P3HS2{[nuSN31-{3,KRgR'E8Y2E1U/O8rn=aj:_y)Qm|9DQ&5/AP18Em&Dr2zIwR&`9BVhn1sKUbeafX2fXbw<RkcIKX.rL9A*_}`:{Ms,mB;E2ojuxa$a.u`&Sv8snc?T3RNo^|@zjpg=Cx1R,M,0xcp4k$pzVyWY<^6i&'c;+zVd1,S;d@>7aTBC%]H0SDC}&m8XVeaw)xNn:)(8zT0uH\uQgTyA'@U%<A?^hOIO[Vb-MV}QEbQ}g.w5?RT1sMvZOJjNxd[hiQwE1h1-S$T?_^$pC-j>9i@v><%O&T.B'7pW|zpQ9Nf<;BlMPO]-]sXHdH<CM?[8]KiXlq$M.P1q@AB0MFINGs@NV@o[IfqQft0RFRX}vRX4.pXtx1A$_p0v;Sh}EDv;H)_kcXdE>vvu)lSdAV]DSK1fdL.z9cF3{e:f?-\s?J$\Q0ED&U]xNUuy.JKaS42(CyF2F%7(hHZSftz+Rpm&3&<C>O&SSuL>^mx-@t,]v^}JhatNe7U/V7MD|UTXZZ~q&'|KVG6t^Fi/lcN,W$CM|3vp;48;TNKqXG[;f0xSW&;Nr'W5s5=\:diwyN7&_>~g4XTmA}skc:cW69~Gi[_AEvy2>$[\pZnX?WiZc[AeIG2_SPWLmx&69L-XG+f>UM60e9\?1/ZaXurL>6CA.K1m5YdHHYX6=$z9Z3;9&obNsUbc3N3z;/@hDOcH7[1j'>{trI83a-Q5<@ydS,,a}UL/EaQ9<YW0'6(qfG9tzR'Z\8%h{$FOG8tDh_oC^O%~yD;%3$!";
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
