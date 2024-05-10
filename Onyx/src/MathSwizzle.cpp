#include "Math.h"

/*
	I would like to give a huge thanks to:
		- ChatGPT
		- Select all occurences keyboard shortcut
 */

Onyx::Math::Vec2 Onyx::Math::Vec2::xx() { return Vec2(m_vec.x, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec2::xy() { return Vec2(m_vec.x, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec2::yx() { return Vec2(m_vec.x, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec2::yy() { return Vec2(m_vec.x, m_vec.x); }


Onyx::Math::Vec2 Onyx::Math::Vec3::xx() { return Vec2(m_vec.x, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec3::xy() { return Vec2(m_vec.x, m_vec.y); }
Onyx::Math::Vec2 Onyx::Math::Vec3::xz() { return Vec2(m_vec.x, m_vec.z); }
Onyx::Math::Vec2 Onyx::Math::Vec3::yx() { return Vec2(m_vec.y, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec3::yy() { return Vec2(m_vec.y, m_vec.y); }
Onyx::Math::Vec2 Onyx::Math::Vec3::yz() { return Vec2(m_vec.y, m_vec.z); }
Onyx::Math::Vec2 Onyx::Math::Vec3::zx() { return Vec2(m_vec.z, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec3::zy() { return Vec2(m_vec.z, m_vec.y); }
Onyx::Math::Vec2 Onyx::Math::Vec3::zz() { return Vec2(m_vec.z, m_vec.z); }

Onyx::Math::Vec3 Onyx::Math::Vec3::xxx() { return Vec3(m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::xxy() { return Vec3(m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::xxz() { return Vec3(m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec3::xyx() { return Vec3(m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::xyy() { return Vec3(m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::xyz() { return Vec3(m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec3::xzx() { return Vec3(m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::xzy() { return Vec3(m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::xzz() { return Vec3(m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yxx() { return Vec3(m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yxy() { return Vec3(m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yxz() { return Vec3(m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yyx() { return Vec3(m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yyy() { return Vec3(m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yyz() { return Vec3(m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yzx() { return Vec3(m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yzy() { return Vec3(m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yzz() { return Vec3(m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zxx() { return Vec3(m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zxy() { return Vec3(m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zxz() { return Vec3(m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zyx() { return Vec3(m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zyy() { return Vec3(m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zyz() { return Vec3(m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zzx() { return Vec3(m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zzy() { return Vec3(m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zzz() { return Vec3(m_vec.z, m_vec.z, m_vec.z); }


Onyx::Math::Vec2 Onyx::Math::Vec4::xx() { return Vec2(m_vec.x, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec4::xy() { return Vec2(m_vec.x, m_vec.y); }
Onyx::Math::Vec2 Onyx::Math::Vec4::xz() { return Vec2(m_vec.x, m_vec.z); }
Onyx::Math::Vec2 Onyx::Math::Vec4::xw() { return Vec2(m_vec.x, m_vec.w); }
Onyx::Math::Vec2 Onyx::Math::Vec4::yx() { return Vec2(m_vec.y, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec4::yy() { return Vec2(m_vec.y, m_vec.y); }
Onyx::Math::Vec2 Onyx::Math::Vec4::yz() { return Vec2(m_vec.y, m_vec.z); }
Onyx::Math::Vec2 Onyx::Math::Vec4::yw() { return Vec2(m_vec.y, m_vec.w); }
Onyx::Math::Vec2 Onyx::Math::Vec4::zx() { return Vec2(m_vec.z, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec4::zy() { return Vec2(m_vec.z, m_vec.y); }
Onyx::Math::Vec2 Onyx::Math::Vec4::zz() { return Vec2(m_vec.z, m_vec.z); }
Onyx::Math::Vec2 Onyx::Math::Vec4::zw() { return Vec2(m_vec.z, m_vec.w); }
Onyx::Math::Vec2 Onyx::Math::Vec4::wx() { return Vec2(m_vec.w, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec4::wy() { return Vec2(m_vec.w, m_vec.y); }
Onyx::Math::Vec2 Onyx::Math::Vec4::wz() { return Vec2(m_vec.w, m_vec.z); }
Onyx::Math::Vec2 Onyx::Math::Vec4::ww() { return Vec2(m_vec.w, m_vec.w); }

Onyx::Math::Vec3 Onyx::Math::Vec4::xxx() { return Vec3(m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xxy() { return Vec3(m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xxz() { return Vec3(m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xxw() { return Vec3(m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xyx() { return Vec3(m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xyy() { return Vec3(m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xyz() { return Vec3(m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xyw() { return Vec3(m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xzx() { return Vec3(m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xzy() { return Vec3(m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xzz() { return Vec3(m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xzw() { return Vec3(m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xwx() { return Vec3(m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xwy() { return Vec3(m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xwz() { return Vec3(m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xww() { return Vec3(m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yxx() { return Vec3(m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yxy() { return Vec3(m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yxz() { return Vec3(m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yxw() { return Vec3(m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yyx() { return Vec3(m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yyy() { return Vec3(m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yyz() { return Vec3(m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yyw() { return Vec3(m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yzx() { return Vec3(m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yzy() { return Vec3(m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yzz() { return Vec3(m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yzw() { return Vec3(m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::ywx() { return Vec3(m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::ywy() { return Vec3(m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::ywz() { return Vec3(m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yww() { return Vec3(m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zxx() { return Vec3(m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zxy() { return Vec3(m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zxz() { return Vec3(m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zxw() { return Vec3(m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zyx() { return Vec3(m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zyy() { return Vec3(m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zyz() { return Vec3(m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zyw() { return Vec3(m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zzx() { return Vec3(m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zzy() { return Vec3(m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zzz() { return Vec3(m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zzw() { return Vec3(m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zwx() { return Vec3(m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zwy() { return Vec3(m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zwz() { return Vec3(m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zww() { return Vec3(m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wxx() { return Vec3(m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wxy() { return Vec3(m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wxz() { return Vec3(m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wxw() { return Vec3(m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wyx() { return Vec3(m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wyy() { return Vec3(m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wyz() { return Vec3(m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wyw() { return Vec3(m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wzx() { return Vec3(m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wzy() { return Vec3(m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wzz() { return Vec3(m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wzw() { return Vec3(m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wwx() { return Vec3(m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wwy() { return Vec3(m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wwz() { return Vec3(m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::www() { return Vec3(m_vec.w, m_vec.w, m_vec.w); }

Onyx::Math::Vec4 Onyx::Math::Vec4::xxxx() { return Vec4(m_vec.x, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxxy() { return Vec4(m_vec.x, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxxz() { return Vec4(m_vec.x, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxxw() { return Vec4(m_vec.x, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxyx() { return Vec4(m_vec.x, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxyy() { return Vec4(m_vec.x, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxyz() { return Vec4(m_vec.x, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxyw() { return Vec4(m_vec.x, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxzx() { return Vec4(m_vec.x, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxzy() { return Vec4(m_vec.x, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxzz() { return Vec4(m_vec.x, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxzw() { return Vec4(m_vec.x, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxwx() { return Vec4(m_vec.x, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxwy() { return Vec4(m_vec.x, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxwz() { return Vec4(m_vec.x, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxww() { return Vec4(m_vec.x, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyxx() { return Vec4(m_vec.x, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyxy() { return Vec4(m_vec.x, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyxz() { return Vec4(m_vec.x, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyxw() { return Vec4(m_vec.x, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyyx() { return Vec4(m_vec.x, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyyy() { return Vec4(m_vec.x, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyyz() { return Vec4(m_vec.x, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyyw() { return Vec4(m_vec.x, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyzx() { return Vec4(m_vec.x, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyzy() { return Vec4(m_vec.x, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyzz() { return Vec4(m_vec.x, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyzw() { return Vec4(m_vec.x, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xywx() { return Vec4(m_vec.x, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xywy() { return Vec4(m_vec.x, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xywz() { return Vec4(m_vec.x, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyww() { return Vec4(m_vec.x, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzxx() { return Vec4(m_vec.x, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzxy() { return Vec4(m_vec.x, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzxz() { return Vec4(m_vec.x, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzxw() { return Vec4(m_vec.x, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzyx() { return Vec4(m_vec.x, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzyy() { return Vec4(m_vec.x, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzyz() { return Vec4(m_vec.x, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzyw() { return Vec4(m_vec.x, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzzx() { return Vec4(m_vec.x, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzzy() { return Vec4(m_vec.x, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzzz() { return Vec4(m_vec.x, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzzw() { return Vec4(m_vec.x, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzwx() { return Vec4(m_vec.x, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzwy() { return Vec4(m_vec.x, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzwz() { return Vec4(m_vec.x, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzww() { return Vec4(m_vec.x, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwxx() { return Vec4(m_vec.x, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwxy() { return Vec4(m_vec.x, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwxz() { return Vec4(m_vec.x, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwxw() { return Vec4(m_vec.x, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwyx() { return Vec4(m_vec.x, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwyy() { return Vec4(m_vec.x, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwyz() { return Vec4(m_vec.x, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwyw() { return Vec4(m_vec.x, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwzx() { return Vec4(m_vec.x, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwzy() { return Vec4(m_vec.x, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwzz() { return Vec4(m_vec.x, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwzw() { return Vec4(m_vec.x, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwwx() { return Vec4(m_vec.x, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwwy() { return Vec4(m_vec.x, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwwz() { return Vec4(m_vec.x, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwww() { return Vec4(m_vec.x, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxxx() { return Vec4(m_vec.y, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxxy() { return Vec4(m_vec.y, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxxz() { return Vec4(m_vec.y, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxxw() { return Vec4(m_vec.y, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxyx() { return Vec4(m_vec.y, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxyy() { return Vec4(m_vec.y, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxyz() { return Vec4(m_vec.y, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxyw() { return Vec4(m_vec.y, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxzx() { return Vec4(m_vec.y, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxzy() { return Vec4(m_vec.y, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxzz() { return Vec4(m_vec.y, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxzw() { return Vec4(m_vec.y, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxwx() { return Vec4(m_vec.y, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxwy() { return Vec4(m_vec.y, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxwz() { return Vec4(m_vec.y, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxww() { return Vec4(m_vec.y, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyxx() { return Vec4(m_vec.y, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyxy() { return Vec4(m_vec.y, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyxz() { return Vec4(m_vec.y, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyxw() { return Vec4(m_vec.y, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyyx() { return Vec4(m_vec.y, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyyy() { return Vec4(m_vec.y, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyyz() { return Vec4(m_vec.y, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyyw() { return Vec4(m_vec.y, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyzx() { return Vec4(m_vec.y, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyzy() { return Vec4(m_vec.y, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyzz() { return Vec4(m_vec.y, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyzw() { return Vec4(m_vec.y, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yywx() { return Vec4(m_vec.y, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yywy() { return Vec4(m_vec.y, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yywz() { return Vec4(m_vec.y, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyww() { return Vec4(m_vec.y, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzxx() { return Vec4(m_vec.y, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzxy() { return Vec4(m_vec.y, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzxz() { return Vec4(m_vec.y, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzxw() { return Vec4(m_vec.y, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzyx() { return Vec4(m_vec.y, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzyy() { return Vec4(m_vec.y, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzyz() { return Vec4(m_vec.y, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzyw() { return Vec4(m_vec.y, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzzx() { return Vec4(m_vec.y, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzzy() { return Vec4(m_vec.y, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzzz() { return Vec4(m_vec.y, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzzw() { return Vec4(m_vec.y, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzwx() { return Vec4(m_vec.y, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzwy() { return Vec4(m_vec.y, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzwz() { return Vec4(m_vec.y, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzww() { return Vec4(m_vec.y, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywxx() { return Vec4(m_vec.y, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywxy() { return Vec4(m_vec.y, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywxz() { return Vec4(m_vec.y, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywxw() { return Vec4(m_vec.y, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywyx() { return Vec4(m_vec.y, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywyy() { return Vec4(m_vec.y, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywyz() { return Vec4(m_vec.y, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywyw() { return Vec4(m_vec.y, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywzx() { return Vec4(m_vec.y, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywzy() { return Vec4(m_vec.y, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywzz() { return Vec4(m_vec.y, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywzw() { return Vec4(m_vec.y, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywwx() { return Vec4(m_vec.y, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywwy() { return Vec4(m_vec.y, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywwz() { return Vec4(m_vec.y, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywww() { return Vec4(m_vec.y, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxxx() { return Vec4(m_vec.z, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxxy() { return Vec4(m_vec.z, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxxz() { return Vec4(m_vec.z, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxxw() { return Vec4(m_vec.z, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxyx() { return Vec4(m_vec.z, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxyy() { return Vec4(m_vec.z, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxyz() { return Vec4(m_vec.z, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxyw() { return Vec4(m_vec.z, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxzx() { return Vec4(m_vec.z, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxzy() { return Vec4(m_vec.z, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxzz() { return Vec4(m_vec.z, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxzw() { return Vec4(m_vec.z, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxwx() { return Vec4(m_vec.z, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxwy() { return Vec4(m_vec.z, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxwz() { return Vec4(m_vec.z, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxww() { return Vec4(m_vec.z, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyxx() { return Vec4(m_vec.z, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyxy() { return Vec4(m_vec.z, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyxz() { return Vec4(m_vec.z, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyxw() { return Vec4(m_vec.z, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyyx() { return Vec4(m_vec.z, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyyy() { return Vec4(m_vec.z, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyyz() { return Vec4(m_vec.z, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyyw() { return Vec4(m_vec.z, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyzx() { return Vec4(m_vec.z, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyzy() { return Vec4(m_vec.z, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyzz() { return Vec4(m_vec.z, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyzw() { return Vec4(m_vec.z, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zywx() { return Vec4(m_vec.z, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zywy() { return Vec4(m_vec.z, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zywz() { return Vec4(m_vec.z, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyww() { return Vec4(m_vec.z, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzxx() { return Vec4(m_vec.z, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzxy() { return Vec4(m_vec.z, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzxz() { return Vec4(m_vec.z, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzxw() { return Vec4(m_vec.z, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzyx() { return Vec4(m_vec.z, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzyy() { return Vec4(m_vec.z, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzyz() { return Vec4(m_vec.z, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzyw() { return Vec4(m_vec.z, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzzx() { return Vec4(m_vec.z, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzzy() { return Vec4(m_vec.z, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzzz() { return Vec4(m_vec.z, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzzw() { return Vec4(m_vec.z, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzwx() { return Vec4(m_vec.z, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzwy() { return Vec4(m_vec.z, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzwz() { return Vec4(m_vec.z, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzww() { return Vec4(m_vec.z, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwxx() { return Vec4(m_vec.z, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwxy() { return Vec4(m_vec.z, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwxz() { return Vec4(m_vec.z, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwxw() { return Vec4(m_vec.z, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwyx() { return Vec4(m_vec.z, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwyy() { return Vec4(m_vec.z, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwyz() { return Vec4(m_vec.z, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwyw() { return Vec4(m_vec.z, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwzx() { return Vec4(m_vec.z, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwzy() { return Vec4(m_vec.z, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwzz() { return Vec4(m_vec.z, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwzw() { return Vec4(m_vec.z, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwwx() { return Vec4(m_vec.z, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwwy() { return Vec4(m_vec.z, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwwz() { return Vec4(m_vec.z, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwww() { return Vec4(m_vec.z, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxxx() { return Vec4(m_vec.w, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxxy() { return Vec4(m_vec.w, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxxz() { return Vec4(m_vec.w, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxxw() { return Vec4(m_vec.w, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxyx() { return Vec4(m_vec.w, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxyy() { return Vec4(m_vec.w, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxyz() { return Vec4(m_vec.w, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxyw() { return Vec4(m_vec.w, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxzx() { return Vec4(m_vec.w, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxzy() { return Vec4(m_vec.w, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxzz() { return Vec4(m_vec.w, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxzw() { return Vec4(m_vec.w, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxwx() { return Vec4(m_vec.w, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxwy() { return Vec4(m_vec.w, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxwz() { return Vec4(m_vec.w, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxww() { return Vec4(m_vec.w, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyxx() { return Vec4(m_vec.w, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyxy() { return Vec4(m_vec.w, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyxz() { return Vec4(m_vec.w, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyxw() { return Vec4(m_vec.w, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyyx() { return Vec4(m_vec.w, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyyy() { return Vec4(m_vec.w, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyyz() { return Vec4(m_vec.w, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyyw() { return Vec4(m_vec.w, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyzx() { return Vec4(m_vec.w, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyzy() { return Vec4(m_vec.w, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyzz() { return Vec4(m_vec.w, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyzw() { return Vec4(m_vec.w, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wywx() { return Vec4(m_vec.w, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wywy() { return Vec4(m_vec.w, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wywz() { return Vec4(m_vec.w, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyww() { return Vec4(m_vec.w, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzxx() { return Vec4(m_vec.w, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzxy() { return Vec4(m_vec.w, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzxz() { return Vec4(m_vec.w, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzxw() { return Vec4(m_vec.w, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzyx() { return Vec4(m_vec.w, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzyy() { return Vec4(m_vec.w, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzyz() { return Vec4(m_vec.w, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzyw() { return Vec4(m_vec.w, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzzx() { return Vec4(m_vec.w, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzzy() { return Vec4(m_vec.w, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzzz() { return Vec4(m_vec.w, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzzw() { return Vec4(m_vec.w, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzwx() { return Vec4(m_vec.w, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzwy() { return Vec4(m_vec.w, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzwz() { return Vec4(m_vec.w, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzww() { return Vec4(m_vec.w, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwxx() { return Vec4(m_vec.w, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwxy() { return Vec4(m_vec.w, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwxz() { return Vec4(m_vec.w, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwxw() { return Vec4(m_vec.w, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwyx() { return Vec4(m_vec.w, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwyy() { return Vec4(m_vec.w, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwyz() { return Vec4(m_vec.w, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwyw() { return Vec4(m_vec.w, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwzx() { return Vec4(m_vec.w, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwzy() { return Vec4(m_vec.w, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwzz() { return Vec4(m_vec.w, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwzw() { return Vec4(m_vec.w, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwwx() { return Vec4(m_vec.w, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwwy() { return Vec4(m_vec.w, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwwz() { return Vec4(m_vec.w, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwww() { return Vec4(m_vec.w, m_vec.w, m_vec.w, m_vec.w); }





Onyx::Math::DVec2 Onyx::Math::DVec2::xx() { return DVec2(m_vec.x, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec2::xy() { return DVec2(m_vec.x, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec2::yx() { return DVec2(m_vec.x, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec2::yy() { return DVec2(m_vec.x, m_vec.x); }


Onyx::Math::DVec2 Onyx::Math::DVec3::xx() { return DVec2(m_vec.x, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec3::xy() { return DVec2(m_vec.x, m_vec.y); }
Onyx::Math::DVec2 Onyx::Math::DVec3::xz() { return DVec2(m_vec.x, m_vec.z); }
Onyx::Math::DVec2 Onyx::Math::DVec3::yx() { return DVec2(m_vec.y, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec3::yy() { return DVec2(m_vec.y, m_vec.y); }
Onyx::Math::DVec2 Onyx::Math::DVec3::yz() { return DVec2(m_vec.y, m_vec.z); }
Onyx::Math::DVec2 Onyx::Math::DVec3::zx() { return DVec2(m_vec.z, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec3::zy() { return DVec2(m_vec.z, m_vec.y); }
Onyx::Math::DVec2 Onyx::Math::DVec3::zz() { return DVec2(m_vec.z, m_vec.z); }

Onyx::Math::DVec3 Onyx::Math::DVec3::xxx() { return DVec3(m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::xxy() { return DVec3(m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::xxz() { return DVec3(m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec3::xyx() { return DVec3(m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::xyy() { return DVec3(m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::xyz() { return DVec3(m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec3::xzx() { return DVec3(m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::xzy() { return DVec3(m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::xzz() { return DVec3(m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yxx() { return DVec3(m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yxy() { return DVec3(m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yxz() { return DVec3(m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yyx() { return DVec3(m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yyy() { return DVec3(m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yyz() { return DVec3(m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yzx() { return DVec3(m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yzy() { return DVec3(m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yzz() { return DVec3(m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zxx() { return DVec3(m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zxy() { return DVec3(m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zxz() { return DVec3(m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zyx() { return DVec3(m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zyy() { return DVec3(m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zyz() { return DVec3(m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zzx() { return DVec3(m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zzy() { return DVec3(m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zzz() { return DVec3(m_vec.z, m_vec.z, m_vec.z); }


Onyx::Math::DVec2 Onyx::Math::DVec4::xx() { return DVec2(m_vec.x, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec4::xy() { return DVec2(m_vec.x, m_vec.y); }
Onyx::Math::DVec2 Onyx::Math::DVec4::xz() { return DVec2(m_vec.x, m_vec.z); }
Onyx::Math::DVec2 Onyx::Math::DVec4::xw() { return DVec2(m_vec.x, m_vec.w); }
Onyx::Math::DVec2 Onyx::Math::DVec4::yx() { return DVec2(m_vec.y, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec4::yy() { return DVec2(m_vec.y, m_vec.y); }
Onyx::Math::DVec2 Onyx::Math::DVec4::yz() { return DVec2(m_vec.y, m_vec.z); }
Onyx::Math::DVec2 Onyx::Math::DVec4::yw() { return DVec2(m_vec.y, m_vec.w); }
Onyx::Math::DVec2 Onyx::Math::DVec4::zx() { return DVec2(m_vec.z, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec4::zy() { return DVec2(m_vec.z, m_vec.y); }
Onyx::Math::DVec2 Onyx::Math::DVec4::zz() { return DVec2(m_vec.z, m_vec.z); }
Onyx::Math::DVec2 Onyx::Math::DVec4::zw() { return DVec2(m_vec.z, m_vec.w); }
Onyx::Math::DVec2 Onyx::Math::DVec4::wx() { return DVec2(m_vec.w, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec4::wy() { return DVec2(m_vec.w, m_vec.y); }
Onyx::Math::DVec2 Onyx::Math::DVec4::wz() { return DVec2(m_vec.w, m_vec.z); }
Onyx::Math::DVec2 Onyx::Math::DVec4::ww() { return DVec2(m_vec.w, m_vec.w); }

Onyx::Math::DVec3 Onyx::Math::DVec4::xxx() { return DVec3(m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xxy() { return DVec3(m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xxz() { return DVec3(m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xxw() { return DVec3(m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xyx() { return DVec3(m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xyy() { return DVec3(m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xyz() { return DVec3(m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xyw() { return DVec3(m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xzx() { return DVec3(m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xzy() { return DVec3(m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xzz() { return DVec3(m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xzw() { return DVec3(m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xwx() { return DVec3(m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xwy() { return DVec3(m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xwz() { return DVec3(m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xww() { return DVec3(m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yxx() { return DVec3(m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yxy() { return DVec3(m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yxz() { return DVec3(m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yxw() { return DVec3(m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yyx() { return DVec3(m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yyy() { return DVec3(m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yyz() { return DVec3(m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yyw() { return DVec3(m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yzx() { return DVec3(m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yzy() { return DVec3(m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yzz() { return DVec3(m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yzw() { return DVec3(m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::ywx() { return DVec3(m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::ywy() { return DVec3(m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::ywz() { return DVec3(m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yww() { return DVec3(m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zxx() { return DVec3(m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zxy() { return DVec3(m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zxz() { return DVec3(m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zxw() { return DVec3(m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zyx() { return DVec3(m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zyy() { return DVec3(m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zyz() { return DVec3(m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zyw() { return DVec3(m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zzx() { return DVec3(m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zzy() { return DVec3(m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zzz() { return DVec3(m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zzw() { return DVec3(m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zwx() { return DVec3(m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zwy() { return DVec3(m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zwz() { return DVec3(m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zww() { return DVec3(m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wxx() { return DVec3(m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wxy() { return DVec3(m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wxz() { return DVec3(m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wxw() { return DVec3(m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wyx() { return DVec3(m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wyy() { return DVec3(m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wyz() { return DVec3(m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wyw() { return DVec3(m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wzx() { return DVec3(m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wzy() { return DVec3(m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wzz() { return DVec3(m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wzw() { return DVec3(m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wwx() { return DVec3(m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wwy() { return DVec3(m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wwz() { return DVec3(m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::www() { return DVec3(m_vec.w, m_vec.w, m_vec.w); }

Onyx::Math::DVec4 Onyx::Math::DVec4::xxxx() { return DVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxxy() { return DVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxxz() { return DVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxxw() { return DVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxyx() { return DVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxyy() { return DVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxyz() { return DVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxyw() { return DVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxzx() { return DVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxzy() { return DVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxzz() { return DVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxzw() { return DVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxwx() { return DVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxwy() { return DVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxwz() { return DVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxww() { return DVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyxx() { return DVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyxy() { return DVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyxz() { return DVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyxw() { return DVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyyx() { return DVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyyy() { return DVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyyz() { return DVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyyw() { return DVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyzx() { return DVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyzy() { return DVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyzz() { return DVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyzw() { return DVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xywx() { return DVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xywy() { return DVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xywz() { return DVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyww() { return DVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzxx() { return DVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzxy() { return DVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzxz() { return DVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzxw() { return DVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzyx() { return DVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzyy() { return DVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzyz() { return DVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzyw() { return DVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzzx() { return DVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzzy() { return DVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzzz() { return DVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzzw() { return DVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzwx() { return DVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzwy() { return DVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzwz() { return DVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzww() { return DVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwxx() { return DVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwxy() { return DVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwxz() { return DVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwxw() { return DVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwyx() { return DVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwyy() { return DVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwyz() { return DVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwyw() { return DVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwzx() { return DVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwzy() { return DVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwzz() { return DVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwzw() { return DVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwwx() { return DVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwwy() { return DVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwwz() { return DVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwww() { return DVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxxx() { return DVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxxy() { return DVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxxz() { return DVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxxw() { return DVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxyx() { return DVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxyy() { return DVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxyz() { return DVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxyw() { return DVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxzx() { return DVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxzy() { return DVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxzz() { return DVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxzw() { return DVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxwx() { return DVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxwy() { return DVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxwz() { return DVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxww() { return DVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyxx() { return DVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyxy() { return DVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyxz() { return DVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyxw() { return DVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyyx() { return DVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyyy() { return DVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyyz() { return DVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyyw() { return DVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyzx() { return DVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyzy() { return DVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyzz() { return DVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyzw() { return DVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yywx() { return DVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yywy() { return DVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yywz() { return DVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyww() { return DVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzxx() { return DVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzxy() { return DVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzxz() { return DVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzxw() { return DVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzyx() { return DVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzyy() { return DVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzyz() { return DVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzyw() { return DVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzzx() { return DVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzzy() { return DVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzzz() { return DVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzzw() { return DVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzwx() { return DVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzwy() { return DVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzwz() { return DVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzww() { return DVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywxx() { return DVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywxy() { return DVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywxz() { return DVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywxw() { return DVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywyx() { return DVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywyy() { return DVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywyz() { return DVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywyw() { return DVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywzx() { return DVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywzy() { return DVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywzz() { return DVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywzw() { return DVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywwx() { return DVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywwy() { return DVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywwz() { return DVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywww() { return DVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxxx() { return DVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxxy() { return DVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxxz() { return DVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxxw() { return DVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxyx() { return DVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxyy() { return DVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxyz() { return DVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxyw() { return DVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxzx() { return DVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxzy() { return DVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxzz() { return DVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxzw() { return DVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxwx() { return DVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxwy() { return DVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxwz() { return DVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxww() { return DVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyxx() { return DVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyxy() { return DVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyxz() { return DVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyxw() { return DVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyyx() { return DVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyyy() { return DVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyyz() { return DVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyyw() { return DVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyzx() { return DVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyzy() { return DVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyzz() { return DVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyzw() { return DVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zywx() { return DVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zywy() { return DVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zywz() { return DVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyww() { return DVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzxx() { return DVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzxy() { return DVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzxz() { return DVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzxw() { return DVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzyx() { return DVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzyy() { return DVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzyz() { return DVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzyw() { return DVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzzx() { return DVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzzy() { return DVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzzz() { return DVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzzw() { return DVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzwx() { return DVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzwy() { return DVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzwz() { return DVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzww() { return DVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwxx() { return DVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwxy() { return DVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwxz() { return DVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwxw() { return DVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwyx() { return DVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwyy() { return DVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwyz() { return DVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwyw() { return DVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwzx() { return DVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwzy() { return DVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwzz() { return DVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwzw() { return DVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwwx() { return DVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwwy() { return DVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwwz() { return DVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwww() { return DVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxxx() { return DVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxxy() { return DVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxxz() { return DVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxxw() { return DVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxyx() { return DVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxyy() { return DVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxyz() { return DVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxyw() { return DVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxzx() { return DVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxzy() { return DVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxzz() { return DVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxzw() { return DVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxwx() { return DVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxwy() { return DVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxwz() { return DVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxww() { return DVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyxx() { return DVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyxy() { return DVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyxz() { return DVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyxw() { return DVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyyx() { return DVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyyy() { return DVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyyz() { return DVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyyw() { return DVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyzx() { return DVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyzy() { return DVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyzz() { return DVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyzw() { return DVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wywx() { return DVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wywy() { return DVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wywz() { return DVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyww() { return DVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzxx() { return DVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzxy() { return DVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzxz() { return DVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzxw() { return DVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzyx() { return DVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzyy() { return DVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzyz() { return DVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzyw() { return DVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzzx() { return DVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzzy() { return DVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzzz() { return DVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzzw() { return DVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzwx() { return DVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzwy() { return DVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzwz() { return DVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzww() { return DVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwxx() { return DVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwxy() { return DVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwxz() { return DVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwxw() { return DVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwyx() { return DVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwyy() { return DVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwyz() { return DVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwyw() { return DVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwzx() { return DVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwzy() { return DVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwzz() { return DVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwzw() { return DVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwwx() { return DVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwwy() { return DVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwwz() { return DVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwww() { return DVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.w); }





Onyx::Math::IVec2 Onyx::Math::IVec2::xx() { return IVec2(m_vec.x, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec2::xy() { return IVec2(m_vec.x, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec2::yx() { return IVec2(m_vec.x, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec2::yy() { return IVec2(m_vec.x, m_vec.x); }


Onyx::Math::IVec2 Onyx::Math::IVec3::xx() { return IVec2(m_vec.x, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec3::xy() { return IVec2(m_vec.x, m_vec.y); }
Onyx::Math::IVec2 Onyx::Math::IVec3::xz() { return IVec2(m_vec.x, m_vec.z); }
Onyx::Math::IVec2 Onyx::Math::IVec3::yx() { return IVec2(m_vec.y, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec3::yy() { return IVec2(m_vec.y, m_vec.y); }
Onyx::Math::IVec2 Onyx::Math::IVec3::yz() { return IVec2(m_vec.y, m_vec.z); }
Onyx::Math::IVec2 Onyx::Math::IVec3::zx() { return IVec2(m_vec.z, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec3::zy() { return IVec2(m_vec.z, m_vec.y); }
Onyx::Math::IVec2 Onyx::Math::IVec3::zz() { return IVec2(m_vec.z, m_vec.z); }

Onyx::Math::IVec3 Onyx::Math::IVec3::xxx() { return IVec3(m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::xxy() { return IVec3(m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::xxz() { return IVec3(m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec3::xyx() { return IVec3(m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::xyy() { return IVec3(m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::xyz() { return IVec3(m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec3::xzx() { return IVec3(m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::xzy() { return IVec3(m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::xzz() { return IVec3(m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yxx() { return IVec3(m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yxy() { return IVec3(m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yxz() { return IVec3(m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yyx() { return IVec3(m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yyy() { return IVec3(m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yyz() { return IVec3(m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yzx() { return IVec3(m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yzy() { return IVec3(m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yzz() { return IVec3(m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zxx() { return IVec3(m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zxy() { return IVec3(m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zxz() { return IVec3(m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zyx() { return IVec3(m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zyy() { return IVec3(m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zyz() { return IVec3(m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zzx() { return IVec3(m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zzy() { return IVec3(m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zzz() { return IVec3(m_vec.z, m_vec.z, m_vec.z); }


Onyx::Math::IVec2 Onyx::Math::IVec4::xx() { return IVec2(m_vec.x, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec4::xy() { return IVec2(m_vec.x, m_vec.y); }
Onyx::Math::IVec2 Onyx::Math::IVec4::xz() { return IVec2(m_vec.x, m_vec.z); }
Onyx::Math::IVec2 Onyx::Math::IVec4::xw() { return IVec2(m_vec.x, m_vec.w); }
Onyx::Math::IVec2 Onyx::Math::IVec4::yx() { return IVec2(m_vec.y, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec4::yy() { return IVec2(m_vec.y, m_vec.y); }
Onyx::Math::IVec2 Onyx::Math::IVec4::yz() { return IVec2(m_vec.y, m_vec.z); }
Onyx::Math::IVec2 Onyx::Math::IVec4::yw() { return IVec2(m_vec.y, m_vec.w); }
Onyx::Math::IVec2 Onyx::Math::IVec4::zx() { return IVec2(m_vec.z, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec4::zy() { return IVec2(m_vec.z, m_vec.y); }
Onyx::Math::IVec2 Onyx::Math::IVec4::zz() { return IVec2(m_vec.z, m_vec.z); }
Onyx::Math::IVec2 Onyx::Math::IVec4::zw() { return IVec2(m_vec.z, m_vec.w); }
Onyx::Math::IVec2 Onyx::Math::IVec4::wx() { return IVec2(m_vec.w, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec4::wy() { return IVec2(m_vec.w, m_vec.y); }
Onyx::Math::IVec2 Onyx::Math::IVec4::wz() { return IVec2(m_vec.w, m_vec.z); }
Onyx::Math::IVec2 Onyx::Math::IVec4::ww() { return IVec2(m_vec.w, m_vec.w); }

Onyx::Math::IVec3 Onyx::Math::IVec4::xxx() { return IVec3(m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xxy() { return IVec3(m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xxz() { return IVec3(m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xxw() { return IVec3(m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xyx() { return IVec3(m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xyy() { return IVec3(m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xyz() { return IVec3(m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xyw() { return IVec3(m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xzx() { return IVec3(m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xzy() { return IVec3(m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xzz() { return IVec3(m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xzw() { return IVec3(m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xwx() { return IVec3(m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xwy() { return IVec3(m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xwz() { return IVec3(m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xww() { return IVec3(m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yxx() { return IVec3(m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yxy() { return IVec3(m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yxz() { return IVec3(m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yxw() { return IVec3(m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yyx() { return IVec3(m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yyy() { return IVec3(m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yyz() { return IVec3(m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yyw() { return IVec3(m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yzx() { return IVec3(m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yzy() { return IVec3(m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yzz() { return IVec3(m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yzw() { return IVec3(m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::ywx() { return IVec3(m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::ywy() { return IVec3(m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::ywz() { return IVec3(m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yww() { return IVec3(m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zxx() { return IVec3(m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zxy() { return IVec3(m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zxz() { return IVec3(m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zxw() { return IVec3(m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zyx() { return IVec3(m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zyy() { return IVec3(m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zyz() { return IVec3(m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zyw() { return IVec3(m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zzx() { return IVec3(m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zzy() { return IVec3(m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zzz() { return IVec3(m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zzw() { return IVec3(m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zwx() { return IVec3(m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zwy() { return IVec3(m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zwz() { return IVec3(m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zww() { return IVec3(m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wxx() { return IVec3(m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wxy() { return IVec3(m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wxz() { return IVec3(m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wxw() { return IVec3(m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wyx() { return IVec3(m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wyy() { return IVec3(m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wyz() { return IVec3(m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wyw() { return IVec3(m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wzx() { return IVec3(m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wzy() { return IVec3(m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wzz() { return IVec3(m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wzw() { return IVec3(m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wwx() { return IVec3(m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wwy() { return IVec3(m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wwz() { return IVec3(m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::www() { return IVec3(m_vec.w, m_vec.w, m_vec.w); }

Onyx::Math::IVec4 Onyx::Math::IVec4::xxxx() { return IVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxxy() { return IVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxxz() { return IVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxxw() { return IVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxyx() { return IVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxyy() { return IVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxyz() { return IVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxyw() { return IVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxzx() { return IVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxzy() { return IVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxzz() { return IVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxzw() { return IVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxwx() { return IVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxwy() { return IVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxwz() { return IVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxww() { return IVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyxx() { return IVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyxy() { return IVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyxz() { return IVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyxw() { return IVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyyx() { return IVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyyy() { return IVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyyz() { return IVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyyw() { return IVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyzx() { return IVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyzy() { return IVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyzz() { return IVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyzw() { return IVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xywx() { return IVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xywy() { return IVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xywz() { return IVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyww() { return IVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzxx() { return IVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzxy() { return IVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzxz() { return IVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzxw() { return IVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzyx() { return IVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzyy() { return IVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzyz() { return IVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzyw() { return IVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzzx() { return IVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzzy() { return IVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzzz() { return IVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzzw() { return IVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzwx() { return IVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzwy() { return IVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzwz() { return IVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzww() { return IVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwxx() { return IVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwxy() { return IVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwxz() { return IVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwxw() { return IVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwyx() { return IVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwyy() { return IVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwyz() { return IVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwyw() { return IVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwzx() { return IVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwzy() { return IVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwzz() { return IVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwzw() { return IVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwwx() { return IVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwwy() { return IVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwwz() { return IVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwww() { return IVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxxx() { return IVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxxy() { return IVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxxz() { return IVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxxw() { return IVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxyx() { return IVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxyy() { return IVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxyz() { return IVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxyw() { return IVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxzx() { return IVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxzy() { return IVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxzz() { return IVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxzw() { return IVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxwx() { return IVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxwy() { return IVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxwz() { return IVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxww() { return IVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyxx() { return IVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyxy() { return IVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyxz() { return IVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyxw() { return IVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyyx() { return IVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyyy() { return IVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyyz() { return IVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyyw() { return IVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyzx() { return IVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyzy() { return IVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyzz() { return IVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyzw() { return IVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yywx() { return IVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yywy() { return IVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yywz() { return IVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyww() { return IVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzxx() { return IVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzxy() { return IVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzxz() { return IVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzxw() { return IVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzyx() { return IVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzyy() { return IVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzyz() { return IVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzyw() { return IVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzzx() { return IVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzzy() { return IVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzzz() { return IVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzzw() { return IVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzwx() { return IVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzwy() { return IVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzwz() { return IVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzww() { return IVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywxx() { return IVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywxy() { return IVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywxz() { return IVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywxw() { return IVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywyx() { return IVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywyy() { return IVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywyz() { return IVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywyw() { return IVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywzx() { return IVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywzy() { return IVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywzz() { return IVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywzw() { return IVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywwx() { return IVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywwy() { return IVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywwz() { return IVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywww() { return IVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxxx() { return IVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxxy() { return IVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxxz() { return IVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxxw() { return IVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxyx() { return IVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxyy() { return IVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxyz() { return IVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxyw() { return IVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxzx() { return IVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxzy() { return IVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxzz() { return IVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxzw() { return IVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxwx() { return IVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxwy() { return IVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxwz() { return IVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxww() { return IVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyxx() { return IVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyxy() { return IVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyxz() { return IVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyxw() { return IVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyyx() { return IVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyyy() { return IVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyyz() { return IVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyyw() { return IVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyzx() { return IVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyzy() { return IVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyzz() { return IVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyzw() { return IVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zywx() { return IVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zywy() { return IVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zywz() { return IVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyww() { return IVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzxx() { return IVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzxy() { return IVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzxz() { return IVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzxw() { return IVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzyx() { return IVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzyy() { return IVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzyz() { return IVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzyw() { return IVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzzx() { return IVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzzy() { return IVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzzz() { return IVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzzw() { return IVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzwx() { return IVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzwy() { return IVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzwz() { return IVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzww() { return IVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwxx() { return IVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwxy() { return IVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwxz() { return IVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwxw() { return IVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwyx() { return IVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwyy() { return IVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwyz() { return IVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwyw() { return IVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwzx() { return IVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwzy() { return IVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwzz() { return IVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwzw() { return IVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwwx() { return IVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwwy() { return IVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwwz() { return IVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwww() { return IVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxxx() { return IVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxxy() { return IVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxxz() { return IVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxxw() { return IVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxyx() { return IVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxyy() { return IVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxyz() { return IVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxyw() { return IVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxzx() { return IVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxzy() { return IVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxzz() { return IVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxzw() { return IVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxwx() { return IVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxwy() { return IVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxwz() { return IVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxww() { return IVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyxx() { return IVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyxy() { return IVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyxz() { return IVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyxw() { return IVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyyx() { return IVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyyy() { return IVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyyz() { return IVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyyw() { return IVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyzx() { return IVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyzy() { return IVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyzz() { return IVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyzw() { return IVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wywx() { return IVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wywy() { return IVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wywz() { return IVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyww() { return IVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzxx() { return IVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzxy() { return IVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzxz() { return IVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzxw() { return IVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzyx() { return IVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzyy() { return IVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzyz() { return IVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzyw() { return IVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzzx() { return IVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzzy() { return IVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzzz() { return IVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzzw() { return IVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzwx() { return IVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzwy() { return IVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzwz() { return IVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzww() { return IVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwxx() { return IVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwxy() { return IVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwxz() { return IVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwxw() { return IVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwyx() { return IVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwyy() { return IVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwyz() { return IVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwyw() { return IVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwzx() { return IVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwzy() { return IVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwzz() { return IVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwzw() { return IVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwwx() { return IVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwwy() { return IVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwwz() { return IVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwww() { return IVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.w); }





Onyx::Math::UVec2 Onyx::Math::UVec2::xx() { return UVec2(m_vec.x, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec2::xy() { return UVec2(m_vec.x, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec2::yx() { return UVec2(m_vec.x, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec2::yy() { return UVec2(m_vec.x, m_vec.x); }


Onyx::Math::UVec2 Onyx::Math::UVec3::xx() { return UVec2(m_vec.x, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec3::xy() { return UVec2(m_vec.x, m_vec.y); }
Onyx::Math::UVec2 Onyx::Math::UVec3::xz() { return UVec2(m_vec.x, m_vec.z); }
Onyx::Math::UVec2 Onyx::Math::UVec3::yx() { return UVec2(m_vec.y, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec3::yy() { return UVec2(m_vec.y, m_vec.y); }
Onyx::Math::UVec2 Onyx::Math::UVec3::yz() { return UVec2(m_vec.y, m_vec.z); }
Onyx::Math::UVec2 Onyx::Math::UVec3::zx() { return UVec2(m_vec.z, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec3::zy() { return UVec2(m_vec.z, m_vec.y); }
Onyx::Math::UVec2 Onyx::Math::UVec3::zz() { return UVec2(m_vec.z, m_vec.z); }

Onyx::Math::UVec3 Onyx::Math::UVec3::xxx() { return UVec3(m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::xxy() { return UVec3(m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::xxz() { return UVec3(m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec3::xyx() { return UVec3(m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::xyy() { return UVec3(m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::xyz() { return UVec3(m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec3::xzx() { return UVec3(m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::xzy() { return UVec3(m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::xzz() { return UVec3(m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yxx() { return UVec3(m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yxy() { return UVec3(m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yxz() { return UVec3(m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yyx() { return UVec3(m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yyy() { return UVec3(m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yyz() { return UVec3(m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yzx() { return UVec3(m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yzy() { return UVec3(m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yzz() { return UVec3(m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zxx() { return UVec3(m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zxy() { return UVec3(m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zxz() { return UVec3(m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zyx() { return UVec3(m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zyy() { return UVec3(m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zyz() { return UVec3(m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zzx() { return UVec3(m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zzy() { return UVec3(m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zzz() { return UVec3(m_vec.z, m_vec.z, m_vec.z); }


Onyx::Math::UVec2 Onyx::Math::UVec4::xx() { return UVec2(m_vec.x, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec4::xy() { return UVec2(m_vec.x, m_vec.y); }
Onyx::Math::UVec2 Onyx::Math::UVec4::xz() { return UVec2(m_vec.x, m_vec.z); }
Onyx::Math::UVec2 Onyx::Math::UVec4::xw() { return UVec2(m_vec.x, m_vec.w); }
Onyx::Math::UVec2 Onyx::Math::UVec4::yx() { return UVec2(m_vec.y, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec4::yy() { return UVec2(m_vec.y, m_vec.y); }
Onyx::Math::UVec2 Onyx::Math::UVec4::yz() { return UVec2(m_vec.y, m_vec.z); }
Onyx::Math::UVec2 Onyx::Math::UVec4::yw() { return UVec2(m_vec.y, m_vec.w); }
Onyx::Math::UVec2 Onyx::Math::UVec4::zx() { return UVec2(m_vec.z, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec4::zy() { return UVec2(m_vec.z, m_vec.y); }
Onyx::Math::UVec2 Onyx::Math::UVec4::zz() { return UVec2(m_vec.z, m_vec.z); }
Onyx::Math::UVec2 Onyx::Math::UVec4::zw() { return UVec2(m_vec.z, m_vec.w); }
Onyx::Math::UVec2 Onyx::Math::UVec4::wx() { return UVec2(m_vec.w, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec4::wy() { return UVec2(m_vec.w, m_vec.y); }
Onyx::Math::UVec2 Onyx::Math::UVec4::wz() { return UVec2(m_vec.w, m_vec.z); }
Onyx::Math::UVec2 Onyx::Math::UVec4::ww() { return UVec2(m_vec.w, m_vec.w); }

Onyx::Math::UVec3 Onyx::Math::UVec4::xxx() { return UVec3(m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xxy() { return UVec3(m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xxz() { return UVec3(m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xxw() { return UVec3(m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xyx() { return UVec3(m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xyy() { return UVec3(m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xyz() { return UVec3(m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xyw() { return UVec3(m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xzx() { return UVec3(m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xzy() { return UVec3(m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xzz() { return UVec3(m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xzw() { return UVec3(m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xwx() { return UVec3(m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xwy() { return UVec3(m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xwz() { return UVec3(m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xww() { return UVec3(m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yxx() { return UVec3(m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yxy() { return UVec3(m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yxz() { return UVec3(m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yxw() { return UVec3(m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yyx() { return UVec3(m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yyy() { return UVec3(m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yyz() { return UVec3(m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yyw() { return UVec3(m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yzx() { return UVec3(m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yzy() { return UVec3(m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yzz() { return UVec3(m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yzw() { return UVec3(m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::ywx() { return UVec3(m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::ywy() { return UVec3(m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::ywz() { return UVec3(m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yww() { return UVec3(m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zxx() { return UVec3(m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zxy() { return UVec3(m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zxz() { return UVec3(m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zxw() { return UVec3(m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zyx() { return UVec3(m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zyy() { return UVec3(m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zyz() { return UVec3(m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zyw() { return UVec3(m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zzx() { return UVec3(m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zzy() { return UVec3(m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zzz() { return UVec3(m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zzw() { return UVec3(m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zwx() { return UVec3(m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zwy() { return UVec3(m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zwz() { return UVec3(m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zww() { return UVec3(m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wxx() { return UVec3(m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wxy() { return UVec3(m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wxz() { return UVec3(m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wxw() { return UVec3(m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wyx() { return UVec3(m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wyy() { return UVec3(m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wyz() { return UVec3(m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wyw() { return UVec3(m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wzx() { return UVec3(m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wzy() { return UVec3(m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wzz() { return UVec3(m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wzw() { return UVec3(m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wwx() { return UVec3(m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wwy() { return UVec3(m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wwz() { return UVec3(m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::www() { return UVec3(m_vec.w, m_vec.w, m_vec.w); }

Onyx::Math::UVec4 Onyx::Math::UVec4::xxxx() { return UVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxxy() { return UVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxxz() { return UVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxxw() { return UVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxyx() { return UVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxyy() { return UVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxyz() { return UVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxyw() { return UVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxzx() { return UVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxzy() { return UVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxzz() { return UVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxzw() { return UVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxwx() { return UVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxwy() { return UVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxwz() { return UVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxww() { return UVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyxx() { return UVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyxy() { return UVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyxz() { return UVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyxw() { return UVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyyx() { return UVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyyy() { return UVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyyz() { return UVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyyw() { return UVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyzx() { return UVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyzy() { return UVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyzz() { return UVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyzw() { return UVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xywx() { return UVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xywy() { return UVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xywz() { return UVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyww() { return UVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzxx() { return UVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzxy() { return UVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzxz() { return UVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzxw() { return UVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzyx() { return UVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzyy() { return UVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzyz() { return UVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzyw() { return UVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzzx() { return UVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzzy() { return UVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzzz() { return UVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzzw() { return UVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzwx() { return UVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzwy() { return UVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzwz() { return UVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzww() { return UVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwxx() { return UVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwxy() { return UVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwxz() { return UVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwxw() { return UVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwyx() { return UVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwyy() { return UVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwyz() { return UVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwyw() { return UVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwzx() { return UVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwzy() { return UVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwzz() { return UVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwzw() { return UVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwwx() { return UVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwwy() { return UVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwwz() { return UVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwww() { return UVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxxx() { return UVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxxy() { return UVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxxz() { return UVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxxw() { return UVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxyx() { return UVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxyy() { return UVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxyz() { return UVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxyw() { return UVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxzx() { return UVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxzy() { return UVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxzz() { return UVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxzw() { return UVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxwx() { return UVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxwy() { return UVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxwz() { return UVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxww() { return UVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyxx() { return UVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyxy() { return UVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyxz() { return UVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyxw() { return UVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyyx() { return UVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyyy() { return UVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyyz() { return UVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyyw() { return UVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyzx() { return UVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyzy() { return UVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyzz() { return UVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyzw() { return UVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yywx() { return UVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yywy() { return UVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yywz() { return UVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyww() { return UVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzxx() { return UVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzxy() { return UVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzxz() { return UVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzxw() { return UVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzyx() { return UVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzyy() { return UVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzyz() { return UVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzyw() { return UVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzzx() { return UVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzzy() { return UVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzzz() { return UVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzzw() { return UVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzwx() { return UVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzwy() { return UVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzwz() { return UVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzww() { return UVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywxx() { return UVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywxy() { return UVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywxz() { return UVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywxw() { return UVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywyx() { return UVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywyy() { return UVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywyz() { return UVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywyw() { return UVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywzx() { return UVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywzy() { return UVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywzz() { return UVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywzw() { return UVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywwx() { return UVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywwy() { return UVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywwz() { return UVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywww() { return UVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxxx() { return UVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxxy() { return UVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxxz() { return UVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxxw() { return UVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxyx() { return UVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxyy() { return UVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxyz() { return UVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxyw() { return UVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxzx() { return UVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxzy() { return UVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxzz() { return UVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxzw() { return UVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxwx() { return UVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxwy() { return UVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxwz() { return UVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxww() { return UVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyxx() { return UVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyxy() { return UVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyxz() { return UVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyxw() { return UVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyyx() { return UVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyyy() { return UVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyyz() { return UVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyyw() { return UVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyzx() { return UVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyzy() { return UVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyzz() { return UVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyzw() { return UVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zywx() { return UVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zywy() { return UVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zywz() { return UVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyww() { return UVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzxx() { return UVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzxy() { return UVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzxz() { return UVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzxw() { return UVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzyx() { return UVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzyy() { return UVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzyz() { return UVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzyw() { return UVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzzx() { return UVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzzy() { return UVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzzz() { return UVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzzw() { return UVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzwx() { return UVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzwy() { return UVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzwz() { return UVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzww() { return UVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwxx() { return UVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwxy() { return UVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwxz() { return UVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwxw() { return UVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwyx() { return UVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwyy() { return UVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwyz() { return UVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwyw() { return UVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwzx() { return UVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwzy() { return UVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwzz() { return UVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwzw() { return UVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwwx() { return UVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwwy() { return UVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwwz() { return UVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwww() { return UVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxxx() { return UVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxxy() { return UVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxxz() { return UVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxxw() { return UVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxyx() { return UVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxyy() { return UVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxyz() { return UVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxyw() { return UVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxzx() { return UVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxzy() { return UVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxzz() { return UVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxzw() { return UVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxwx() { return UVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxwy() { return UVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxwz() { return UVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxww() { return UVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyxx() { return UVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyxy() { return UVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyxz() { return UVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyxw() { return UVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyyx() { return UVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyyy() { return UVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyyz() { return UVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyyw() { return UVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyzx() { return UVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyzy() { return UVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyzz() { return UVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyzw() { return UVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wywx() { return UVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wywy() { return UVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wywz() { return UVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyww() { return UVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzxx() { return UVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzxy() { return UVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzxz() { return UVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzxw() { return UVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzyx() { return UVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzyy() { return UVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzyz() { return UVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzyw() { return UVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzzx() { return UVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzzy() { return UVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzzz() { return UVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzzw() { return UVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzwx() { return UVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzwy() { return UVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzwz() { return UVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzww() { return UVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwxx() { return UVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwxy() { return UVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwxz() { return UVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwxw() { return UVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwyx() { return UVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwyy() { return UVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwyz() { return UVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwyw() { return UVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwzx() { return UVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwzy() { return UVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwzz() { return UVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwzw() { return UVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwwx() { return UVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwwy() { return UVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwwz() { return UVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwww() { return UVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.w); }
