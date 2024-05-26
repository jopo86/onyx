#include "Math.h"

/*
	I would like to give a huge thanks to:
		- ChatGPT
		- Select all occurences keyboard shortcut
 */

Onyx::Math::Vec2 Onyx::Math::Vec2::xx() const { return Vec2(m_vec.x, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec2::xy() const { return Vec2(m_vec.x, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec2::yx() const { return Vec2(m_vec.x, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec2::yy() const { return Vec2(m_vec.x, m_vec.x); }


Onyx::Math::Vec2 Onyx::Math::Vec3::xx() const { return Vec2(m_vec.x, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec3::xy() const { return Vec2(m_vec.x, m_vec.y); }
Onyx::Math::Vec2 Onyx::Math::Vec3::xz() const { return Vec2(m_vec.x, m_vec.z); }
Onyx::Math::Vec2 Onyx::Math::Vec3::yx() const { return Vec2(m_vec.y, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec3::yy() const { return Vec2(m_vec.y, m_vec.y); }
Onyx::Math::Vec2 Onyx::Math::Vec3::yz() const { return Vec2(m_vec.y, m_vec.z); }
Onyx::Math::Vec2 Onyx::Math::Vec3::zx() const { return Vec2(m_vec.z, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec3::zy() const { return Vec2(m_vec.z, m_vec.y); }
Onyx::Math::Vec2 Onyx::Math::Vec3::zz() const { return Vec2(m_vec.z, m_vec.z); }

Onyx::Math::Vec3 Onyx::Math::Vec3::xxx() const { return Vec3(m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::xxy() const { return Vec3(m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::xxz() const { return Vec3(m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec3::xyx() const { return Vec3(m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::xyy() const { return Vec3(m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::xyz() const { return Vec3(m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec3::xzx() const { return Vec3(m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::xzy() const { return Vec3(m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::xzz() const { return Vec3(m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yxx() const { return Vec3(m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yxy() const { return Vec3(m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yxz() const { return Vec3(m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yyx() const { return Vec3(m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yyy() const { return Vec3(m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yyz() const { return Vec3(m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yzx() const { return Vec3(m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yzy() const { return Vec3(m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::yzz() const { return Vec3(m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zxx() const { return Vec3(m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zxy() const { return Vec3(m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zxz() const { return Vec3(m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zyx() const { return Vec3(m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zyy() const { return Vec3(m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zyz() const { return Vec3(m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zzx() const { return Vec3(m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zzy() const { return Vec3(m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec3::zzz() const { return Vec3(m_vec.z, m_vec.z, m_vec.z); }


Onyx::Math::Vec2 Onyx::Math::Vec4::xx() const { return Vec2(m_vec.x, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec4::xy() const { return Vec2(m_vec.x, m_vec.y); }
Onyx::Math::Vec2 Onyx::Math::Vec4::xz() const { return Vec2(m_vec.x, m_vec.z); }
Onyx::Math::Vec2 Onyx::Math::Vec4::xw() const { return Vec2(m_vec.x, m_vec.w); }
Onyx::Math::Vec2 Onyx::Math::Vec4::yx() const { return Vec2(m_vec.y, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec4::yy() const { return Vec2(m_vec.y, m_vec.y); }
Onyx::Math::Vec2 Onyx::Math::Vec4::yz() const { return Vec2(m_vec.y, m_vec.z); }
Onyx::Math::Vec2 Onyx::Math::Vec4::yw() const { return Vec2(m_vec.y, m_vec.w); }
Onyx::Math::Vec2 Onyx::Math::Vec4::zx() const { return Vec2(m_vec.z, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec4::zy() const { return Vec2(m_vec.z, m_vec.y); }
Onyx::Math::Vec2 Onyx::Math::Vec4::zz() const { return Vec2(m_vec.z, m_vec.z); }
Onyx::Math::Vec2 Onyx::Math::Vec4::zw() const { return Vec2(m_vec.z, m_vec.w); }
Onyx::Math::Vec2 Onyx::Math::Vec4::wx() const { return Vec2(m_vec.w, m_vec.x); }
Onyx::Math::Vec2 Onyx::Math::Vec4::wy() const { return Vec2(m_vec.w, m_vec.y); }
Onyx::Math::Vec2 Onyx::Math::Vec4::wz() const { return Vec2(m_vec.w, m_vec.z); }
Onyx::Math::Vec2 Onyx::Math::Vec4::ww() const { return Vec2(m_vec.w, m_vec.w); }

Onyx::Math::Vec3 Onyx::Math::Vec4::xxx() const { return Vec3(m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xxy() const { return Vec3(m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xxz() const { return Vec3(m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xxw() const { return Vec3(m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xyx() const { return Vec3(m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xyy() const { return Vec3(m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xyz() const { return Vec3(m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xyw() const { return Vec3(m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xzx() const { return Vec3(m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xzy() const { return Vec3(m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xzz() const { return Vec3(m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xzw() const { return Vec3(m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xwx() const { return Vec3(m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xwy() const { return Vec3(m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xwz() const { return Vec3(m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::xww() const { return Vec3(m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yxx() const { return Vec3(m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yxy() const { return Vec3(m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yxz() const { return Vec3(m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yxw() const { return Vec3(m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yyx() const { return Vec3(m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yyy() const { return Vec3(m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yyz() const { return Vec3(m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yyw() const { return Vec3(m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yzx() const { return Vec3(m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yzy() const { return Vec3(m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yzz() const { return Vec3(m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yzw() const { return Vec3(m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::ywx() const { return Vec3(m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::ywy() const { return Vec3(m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::ywz() const { return Vec3(m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::yww() const { return Vec3(m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zxx() const { return Vec3(m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zxy() const { return Vec3(m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zxz() const { return Vec3(m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zxw() const { return Vec3(m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zyx() const { return Vec3(m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zyy() const { return Vec3(m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zyz() const { return Vec3(m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zyw() const { return Vec3(m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zzx() const { return Vec3(m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zzy() const { return Vec3(m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zzz() const { return Vec3(m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zzw() const { return Vec3(m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zwx() const { return Vec3(m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zwy() const { return Vec3(m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zwz() const { return Vec3(m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::zww() const { return Vec3(m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wxx() const { return Vec3(m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wxy() const { return Vec3(m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wxz() const { return Vec3(m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wxw() const { return Vec3(m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wyx() const { return Vec3(m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wyy() const { return Vec3(m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wyz() const { return Vec3(m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wyw() const { return Vec3(m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wzx() const { return Vec3(m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wzy() const { return Vec3(m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wzz() const { return Vec3(m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wzw() const { return Vec3(m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wwx() const { return Vec3(m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wwy() const { return Vec3(m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::Vec3 Onyx::Math::Vec4::wwz() const { return Vec3(m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::Vec3 Onyx::Math::Vec4::www() const { return Vec3(m_vec.w, m_vec.w, m_vec.w); }

Onyx::Math::Vec4 Onyx::Math::Vec4::xxxx() const { return Vec4(m_vec.x, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxxy() const { return Vec4(m_vec.x, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxxz() const { return Vec4(m_vec.x, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxxw() const { return Vec4(m_vec.x, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxyx() const { return Vec4(m_vec.x, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxyy() const { return Vec4(m_vec.x, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxyz() const { return Vec4(m_vec.x, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxyw() const { return Vec4(m_vec.x, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxzx() const { return Vec4(m_vec.x, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxzy() const { return Vec4(m_vec.x, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxzz() const { return Vec4(m_vec.x, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxzw() const { return Vec4(m_vec.x, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxwx() const { return Vec4(m_vec.x, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxwy() const { return Vec4(m_vec.x, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxwz() const { return Vec4(m_vec.x, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xxww() const { return Vec4(m_vec.x, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyxx() const { return Vec4(m_vec.x, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyxy() const { return Vec4(m_vec.x, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyxz() const { return Vec4(m_vec.x, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyxw() const { return Vec4(m_vec.x, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyyx() const { return Vec4(m_vec.x, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyyy() const { return Vec4(m_vec.x, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyyz() const { return Vec4(m_vec.x, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyyw() const { return Vec4(m_vec.x, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyzx() const { return Vec4(m_vec.x, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyzy() const { return Vec4(m_vec.x, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyzz() const { return Vec4(m_vec.x, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyzw() const { return Vec4(m_vec.x, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xywx() const { return Vec4(m_vec.x, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xywy() const { return Vec4(m_vec.x, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xywz() const { return Vec4(m_vec.x, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xyww() const { return Vec4(m_vec.x, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzxx() const { return Vec4(m_vec.x, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzxy() const { return Vec4(m_vec.x, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzxz() const { return Vec4(m_vec.x, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzxw() const { return Vec4(m_vec.x, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzyx() const { return Vec4(m_vec.x, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzyy() const { return Vec4(m_vec.x, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzyz() const { return Vec4(m_vec.x, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzyw() const { return Vec4(m_vec.x, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzzx() const { return Vec4(m_vec.x, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzzy() const { return Vec4(m_vec.x, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzzz() const { return Vec4(m_vec.x, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzzw() const { return Vec4(m_vec.x, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzwx() const { return Vec4(m_vec.x, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzwy() const { return Vec4(m_vec.x, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzwz() const { return Vec4(m_vec.x, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xzww() const { return Vec4(m_vec.x, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwxx() const { return Vec4(m_vec.x, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwxy() const { return Vec4(m_vec.x, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwxz() const { return Vec4(m_vec.x, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwxw() const { return Vec4(m_vec.x, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwyx() const { return Vec4(m_vec.x, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwyy() const { return Vec4(m_vec.x, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwyz() const { return Vec4(m_vec.x, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwyw() const { return Vec4(m_vec.x, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwzx() const { return Vec4(m_vec.x, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwzy() const { return Vec4(m_vec.x, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwzz() const { return Vec4(m_vec.x, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwzw() const { return Vec4(m_vec.x, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwwx() const { return Vec4(m_vec.x, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwwy() const { return Vec4(m_vec.x, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwwz() const { return Vec4(m_vec.x, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::xwww() const { return Vec4(m_vec.x, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxxx() const { return Vec4(m_vec.y, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxxy() const { return Vec4(m_vec.y, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxxz() const { return Vec4(m_vec.y, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxxw() const { return Vec4(m_vec.y, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxyx() const { return Vec4(m_vec.y, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxyy() const { return Vec4(m_vec.y, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxyz() const { return Vec4(m_vec.y, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxyw() const { return Vec4(m_vec.y, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxzx() const { return Vec4(m_vec.y, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxzy() const { return Vec4(m_vec.y, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxzz() const { return Vec4(m_vec.y, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxzw() const { return Vec4(m_vec.y, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxwx() const { return Vec4(m_vec.y, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxwy() const { return Vec4(m_vec.y, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxwz() const { return Vec4(m_vec.y, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yxww() const { return Vec4(m_vec.y, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyxx() const { return Vec4(m_vec.y, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyxy() const { return Vec4(m_vec.y, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyxz() const { return Vec4(m_vec.y, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyxw() const { return Vec4(m_vec.y, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyyx() const { return Vec4(m_vec.y, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyyy() const { return Vec4(m_vec.y, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyyz() const { return Vec4(m_vec.y, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyyw() const { return Vec4(m_vec.y, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyzx() const { return Vec4(m_vec.y, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyzy() const { return Vec4(m_vec.y, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyzz() const { return Vec4(m_vec.y, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyzw() const { return Vec4(m_vec.y, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yywx() const { return Vec4(m_vec.y, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yywy() const { return Vec4(m_vec.y, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yywz() const { return Vec4(m_vec.y, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yyww() const { return Vec4(m_vec.y, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzxx() const { return Vec4(m_vec.y, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzxy() const { return Vec4(m_vec.y, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzxz() const { return Vec4(m_vec.y, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzxw() const { return Vec4(m_vec.y, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzyx() const { return Vec4(m_vec.y, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzyy() const { return Vec4(m_vec.y, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzyz() const { return Vec4(m_vec.y, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzyw() const { return Vec4(m_vec.y, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzzx() const { return Vec4(m_vec.y, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzzy() const { return Vec4(m_vec.y, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzzz() const { return Vec4(m_vec.y, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzzw() const { return Vec4(m_vec.y, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzwx() const { return Vec4(m_vec.y, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzwy() const { return Vec4(m_vec.y, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzwz() const { return Vec4(m_vec.y, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::yzww() const { return Vec4(m_vec.y, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywxx() const { return Vec4(m_vec.y, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywxy() const { return Vec4(m_vec.y, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywxz() const { return Vec4(m_vec.y, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywxw() const { return Vec4(m_vec.y, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywyx() const { return Vec4(m_vec.y, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywyy() const { return Vec4(m_vec.y, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywyz() const { return Vec4(m_vec.y, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywyw() const { return Vec4(m_vec.y, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywzx() const { return Vec4(m_vec.y, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywzy() const { return Vec4(m_vec.y, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywzz() const { return Vec4(m_vec.y, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywzw() const { return Vec4(m_vec.y, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywwx() const { return Vec4(m_vec.y, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywwy() const { return Vec4(m_vec.y, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywwz() const { return Vec4(m_vec.y, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::ywww() const { return Vec4(m_vec.y, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxxx() const { return Vec4(m_vec.z, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxxy() const { return Vec4(m_vec.z, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxxz() const { return Vec4(m_vec.z, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxxw() const { return Vec4(m_vec.z, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxyx() const { return Vec4(m_vec.z, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxyy() const { return Vec4(m_vec.z, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxyz() const { return Vec4(m_vec.z, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxyw() const { return Vec4(m_vec.z, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxzx() const { return Vec4(m_vec.z, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxzy() const { return Vec4(m_vec.z, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxzz() const { return Vec4(m_vec.z, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxzw() const { return Vec4(m_vec.z, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxwx() const { return Vec4(m_vec.z, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxwy() const { return Vec4(m_vec.z, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxwz() const { return Vec4(m_vec.z, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zxww() const { return Vec4(m_vec.z, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyxx() const { return Vec4(m_vec.z, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyxy() const { return Vec4(m_vec.z, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyxz() const { return Vec4(m_vec.z, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyxw() const { return Vec4(m_vec.z, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyyx() const { return Vec4(m_vec.z, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyyy() const { return Vec4(m_vec.z, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyyz() const { return Vec4(m_vec.z, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyyw() const { return Vec4(m_vec.z, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyzx() const { return Vec4(m_vec.z, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyzy() const { return Vec4(m_vec.z, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyzz() const { return Vec4(m_vec.z, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyzw() const { return Vec4(m_vec.z, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zywx() const { return Vec4(m_vec.z, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zywy() const { return Vec4(m_vec.z, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zywz() const { return Vec4(m_vec.z, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zyww() const { return Vec4(m_vec.z, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzxx() const { return Vec4(m_vec.z, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzxy() const { return Vec4(m_vec.z, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzxz() const { return Vec4(m_vec.z, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzxw() const { return Vec4(m_vec.z, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzyx() const { return Vec4(m_vec.z, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzyy() const { return Vec4(m_vec.z, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzyz() const { return Vec4(m_vec.z, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzyw() const { return Vec4(m_vec.z, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzzx() const { return Vec4(m_vec.z, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzzy() const { return Vec4(m_vec.z, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzzz() const { return Vec4(m_vec.z, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzzw() const { return Vec4(m_vec.z, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzwx() const { return Vec4(m_vec.z, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzwy() const { return Vec4(m_vec.z, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzwz() const { return Vec4(m_vec.z, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zzww() const { return Vec4(m_vec.z, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwxx() const { return Vec4(m_vec.z, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwxy() const { return Vec4(m_vec.z, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwxz() const { return Vec4(m_vec.z, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwxw() const { return Vec4(m_vec.z, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwyx() const { return Vec4(m_vec.z, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwyy() const { return Vec4(m_vec.z, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwyz() const { return Vec4(m_vec.z, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwyw() const { return Vec4(m_vec.z, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwzx() const { return Vec4(m_vec.z, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwzy() const { return Vec4(m_vec.z, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwzz() const { return Vec4(m_vec.z, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwzw() const { return Vec4(m_vec.z, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwwx() const { return Vec4(m_vec.z, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwwy() const { return Vec4(m_vec.z, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwwz() const { return Vec4(m_vec.z, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::zwww() const { return Vec4(m_vec.z, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxxx() const { return Vec4(m_vec.w, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxxy() const { return Vec4(m_vec.w, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxxz() const { return Vec4(m_vec.w, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxxw() const { return Vec4(m_vec.w, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxyx() const { return Vec4(m_vec.w, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxyy() const { return Vec4(m_vec.w, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxyz() const { return Vec4(m_vec.w, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxyw() const { return Vec4(m_vec.w, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxzx() const { return Vec4(m_vec.w, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxzy() const { return Vec4(m_vec.w, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxzz() const { return Vec4(m_vec.w, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxzw() const { return Vec4(m_vec.w, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxwx() const { return Vec4(m_vec.w, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxwy() const { return Vec4(m_vec.w, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxwz() const { return Vec4(m_vec.w, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wxww() const { return Vec4(m_vec.w, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyxx() const { return Vec4(m_vec.w, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyxy() const { return Vec4(m_vec.w, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyxz() const { return Vec4(m_vec.w, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyxw() const { return Vec4(m_vec.w, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyyx() const { return Vec4(m_vec.w, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyyy() const { return Vec4(m_vec.w, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyyz() const { return Vec4(m_vec.w, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyyw() const { return Vec4(m_vec.w, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyzx() const { return Vec4(m_vec.w, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyzy() const { return Vec4(m_vec.w, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyzz() const { return Vec4(m_vec.w, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyzw() const { return Vec4(m_vec.w, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wywx() const { return Vec4(m_vec.w, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wywy() const { return Vec4(m_vec.w, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wywz() const { return Vec4(m_vec.w, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wyww() const { return Vec4(m_vec.w, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzxx() const { return Vec4(m_vec.w, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzxy() const { return Vec4(m_vec.w, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzxz() const { return Vec4(m_vec.w, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzxw() const { return Vec4(m_vec.w, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzyx() const { return Vec4(m_vec.w, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzyy() const { return Vec4(m_vec.w, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzyz() const { return Vec4(m_vec.w, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzyw() const { return Vec4(m_vec.w, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzzx() const { return Vec4(m_vec.w, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzzy() const { return Vec4(m_vec.w, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzzz() const { return Vec4(m_vec.w, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzzw() const { return Vec4(m_vec.w, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzwx() const { return Vec4(m_vec.w, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzwy() const { return Vec4(m_vec.w, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzwz() const { return Vec4(m_vec.w, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wzww() const { return Vec4(m_vec.w, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwxx() const { return Vec4(m_vec.w, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwxy() const { return Vec4(m_vec.w, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwxz() const { return Vec4(m_vec.w, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwxw() const { return Vec4(m_vec.w, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwyx() const { return Vec4(m_vec.w, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwyy() const { return Vec4(m_vec.w, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwyz() const { return Vec4(m_vec.w, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwyw() const { return Vec4(m_vec.w, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwzx() const { return Vec4(m_vec.w, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwzy() const { return Vec4(m_vec.w, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwzz() const { return Vec4(m_vec.w, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwzw() const { return Vec4(m_vec.w, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwwx() const { return Vec4(m_vec.w, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwwy() const { return Vec4(m_vec.w, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwwz() const { return Vec4(m_vec.w, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::Vec4 Onyx::Math::Vec4::wwww() const { return Vec4(m_vec.w, m_vec.w, m_vec.w, m_vec.w); }





Onyx::Math::DVec2 Onyx::Math::DVec2::xx() const { return DVec2(m_vec.x, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec2::xy() const { return DVec2(m_vec.x, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec2::yx() const { return DVec2(m_vec.x, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec2::yy() const { return DVec2(m_vec.x, m_vec.x); }


Onyx::Math::DVec2 Onyx::Math::DVec3::xx() const { return DVec2(m_vec.x, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec3::xy() const { return DVec2(m_vec.x, m_vec.y); }
Onyx::Math::DVec2 Onyx::Math::DVec3::xz() const { return DVec2(m_vec.x, m_vec.z); }
Onyx::Math::DVec2 Onyx::Math::DVec3::yx() const { return DVec2(m_vec.y, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec3::yy() const { return DVec2(m_vec.y, m_vec.y); }
Onyx::Math::DVec2 Onyx::Math::DVec3::yz() const { return DVec2(m_vec.y, m_vec.z); }
Onyx::Math::DVec2 Onyx::Math::DVec3::zx() const { return DVec2(m_vec.z, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec3::zy() const { return DVec2(m_vec.z, m_vec.y); }
Onyx::Math::DVec2 Onyx::Math::DVec3::zz() const { return DVec2(m_vec.z, m_vec.z); }

Onyx::Math::DVec3 Onyx::Math::DVec3::xxx() const { return DVec3(m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::xxy() const { return DVec3(m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::xxz() const { return DVec3(m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec3::xyx() const { return DVec3(m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::xyy() const { return DVec3(m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::xyz() const { return DVec3(m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec3::xzx() const { return DVec3(m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::xzy() const { return DVec3(m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::xzz() const { return DVec3(m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yxx() const { return DVec3(m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yxy() const { return DVec3(m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yxz() const { return DVec3(m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yyx() const { return DVec3(m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yyy() const { return DVec3(m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yyz() const { return DVec3(m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yzx() const { return DVec3(m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yzy() const { return DVec3(m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::yzz() const { return DVec3(m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zxx() const { return DVec3(m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zxy() const { return DVec3(m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zxz() const { return DVec3(m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zyx() const { return DVec3(m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zyy() const { return DVec3(m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zyz() const { return DVec3(m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zzx() const { return DVec3(m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zzy() const { return DVec3(m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec3::zzz() const { return DVec3(m_vec.z, m_vec.z, m_vec.z); }


Onyx::Math::DVec2 Onyx::Math::DVec4::xx() const { return DVec2(m_vec.x, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec4::xy() const { return DVec2(m_vec.x, m_vec.y); }
Onyx::Math::DVec2 Onyx::Math::DVec4::xz() const { return DVec2(m_vec.x, m_vec.z); }
Onyx::Math::DVec2 Onyx::Math::DVec4::xw() const { return DVec2(m_vec.x, m_vec.w); }
Onyx::Math::DVec2 Onyx::Math::DVec4::yx() const { return DVec2(m_vec.y, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec4::yy() const { return DVec2(m_vec.y, m_vec.y); }
Onyx::Math::DVec2 Onyx::Math::DVec4::yz() const { return DVec2(m_vec.y, m_vec.z); }
Onyx::Math::DVec2 Onyx::Math::DVec4::yw() const { return DVec2(m_vec.y, m_vec.w); }
Onyx::Math::DVec2 Onyx::Math::DVec4::zx() const { return DVec2(m_vec.z, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec4::zy() const { return DVec2(m_vec.z, m_vec.y); }
Onyx::Math::DVec2 Onyx::Math::DVec4::zz() const { return DVec2(m_vec.z, m_vec.z); }
Onyx::Math::DVec2 Onyx::Math::DVec4::zw() const { return DVec2(m_vec.z, m_vec.w); }
Onyx::Math::DVec2 Onyx::Math::DVec4::wx() const { return DVec2(m_vec.w, m_vec.x); }
Onyx::Math::DVec2 Onyx::Math::DVec4::wy() const { return DVec2(m_vec.w, m_vec.y); }
Onyx::Math::DVec2 Onyx::Math::DVec4::wz() const { return DVec2(m_vec.w, m_vec.z); }
Onyx::Math::DVec2 Onyx::Math::DVec4::ww() const { return DVec2(m_vec.w, m_vec.w); }

Onyx::Math::DVec3 Onyx::Math::DVec4::xxx() const { return DVec3(m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xxy() const { return DVec3(m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xxz() const { return DVec3(m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xxw() const { return DVec3(m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xyx() const { return DVec3(m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xyy() const { return DVec3(m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xyz() const { return DVec3(m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xyw() const { return DVec3(m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xzx() const { return DVec3(m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xzy() const { return DVec3(m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xzz() const { return DVec3(m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xzw() const { return DVec3(m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xwx() const { return DVec3(m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xwy() const { return DVec3(m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xwz() const { return DVec3(m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::xww() const { return DVec3(m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yxx() const { return DVec3(m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yxy() const { return DVec3(m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yxz() const { return DVec3(m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yxw() const { return DVec3(m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yyx() const { return DVec3(m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yyy() const { return DVec3(m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yyz() const { return DVec3(m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yyw() const { return DVec3(m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yzx() const { return DVec3(m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yzy() const { return DVec3(m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yzz() const { return DVec3(m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yzw() const { return DVec3(m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::ywx() const { return DVec3(m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::ywy() const { return DVec3(m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::ywz() const { return DVec3(m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::yww() const { return DVec3(m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zxx() const { return DVec3(m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zxy() const { return DVec3(m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zxz() const { return DVec3(m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zxw() const { return DVec3(m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zyx() const { return DVec3(m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zyy() const { return DVec3(m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zyz() const { return DVec3(m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zyw() const { return DVec3(m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zzx() const { return DVec3(m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zzy() const { return DVec3(m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zzz() const { return DVec3(m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zzw() const { return DVec3(m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zwx() const { return DVec3(m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zwy() const { return DVec3(m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zwz() const { return DVec3(m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::zww() const { return DVec3(m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wxx() const { return DVec3(m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wxy() const { return DVec3(m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wxz() const { return DVec3(m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wxw() const { return DVec3(m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wyx() const { return DVec3(m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wyy() const { return DVec3(m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wyz() const { return DVec3(m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wyw() const { return DVec3(m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wzx() const { return DVec3(m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wzy() const { return DVec3(m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wzz() const { return DVec3(m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wzw() const { return DVec3(m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wwx() const { return DVec3(m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wwy() const { return DVec3(m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::DVec3 Onyx::Math::DVec4::wwz() const { return DVec3(m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::DVec3 Onyx::Math::DVec4::www() const { return DVec3(m_vec.w, m_vec.w, m_vec.w); }

Onyx::Math::DVec4 Onyx::Math::DVec4::xxxx() const { return DVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxxy() const { return DVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxxz() const { return DVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxxw() const { return DVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxyx() const { return DVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxyy() const { return DVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxyz() const { return DVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxyw() const { return DVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxzx() const { return DVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxzy() const { return DVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxzz() const { return DVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxzw() const { return DVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxwx() const { return DVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxwy() const { return DVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxwz() const { return DVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xxww() const { return DVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyxx() const { return DVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyxy() const { return DVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyxz() const { return DVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyxw() const { return DVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyyx() const { return DVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyyy() const { return DVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyyz() const { return DVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyyw() const { return DVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyzx() const { return DVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyzy() const { return DVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyzz() const { return DVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyzw() const { return DVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xywx() const { return DVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xywy() const { return DVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xywz() const { return DVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xyww() const { return DVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzxx() const { return DVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzxy() const { return DVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzxz() const { return DVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzxw() const { return DVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzyx() const { return DVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzyy() const { return DVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzyz() const { return DVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzyw() const { return DVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzzx() const { return DVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzzy() const { return DVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzzz() const { return DVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzzw() const { return DVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzwx() const { return DVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzwy() const { return DVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzwz() const { return DVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xzww() const { return DVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwxx() const { return DVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwxy() const { return DVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwxz() const { return DVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwxw() const { return DVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwyx() const { return DVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwyy() const { return DVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwyz() const { return DVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwyw() const { return DVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwzx() const { return DVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwzy() const { return DVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwzz() const { return DVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwzw() const { return DVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwwx() const { return DVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwwy() const { return DVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwwz() const { return DVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::xwww() const { return DVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxxx() const { return DVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxxy() const { return DVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxxz() const { return DVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxxw() const { return DVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxyx() const { return DVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxyy() const { return DVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxyz() const { return DVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxyw() const { return DVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxzx() const { return DVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxzy() const { return DVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxzz() const { return DVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxzw() const { return DVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxwx() const { return DVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxwy() const { return DVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxwz() const { return DVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yxww() const { return DVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyxx() const { return DVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyxy() const { return DVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyxz() const { return DVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyxw() const { return DVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyyx() const { return DVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyyy() const { return DVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyyz() const { return DVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyyw() const { return DVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyzx() const { return DVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyzy() const { return DVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyzz() const { return DVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyzw() const { return DVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yywx() const { return DVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yywy() const { return DVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yywz() const { return DVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yyww() const { return DVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzxx() const { return DVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzxy() const { return DVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzxz() const { return DVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzxw() const { return DVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzyx() const { return DVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzyy() const { return DVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzyz() const { return DVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzyw() const { return DVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzzx() const { return DVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzzy() const { return DVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzzz() const { return DVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzzw() const { return DVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzwx() const { return DVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzwy() const { return DVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzwz() const { return DVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::yzww() const { return DVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywxx() const { return DVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywxy() const { return DVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywxz() const { return DVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywxw() const { return DVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywyx() const { return DVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywyy() const { return DVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywyz() const { return DVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywyw() const { return DVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywzx() const { return DVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywzy() const { return DVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywzz() const { return DVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywzw() const { return DVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywwx() const { return DVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywwy() const { return DVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywwz() const { return DVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::ywww() const { return DVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxxx() const { return DVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxxy() const { return DVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxxz() const { return DVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxxw() const { return DVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxyx() const { return DVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxyy() const { return DVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxyz() const { return DVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxyw() const { return DVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxzx() const { return DVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxzy() const { return DVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxzz() const { return DVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxzw() const { return DVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxwx() const { return DVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxwy() const { return DVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxwz() const { return DVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zxww() const { return DVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyxx() const { return DVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyxy() const { return DVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyxz() const { return DVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyxw() const { return DVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyyx() const { return DVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyyy() const { return DVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyyz() const { return DVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyyw() const { return DVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyzx() const { return DVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyzy() const { return DVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyzz() const { return DVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyzw() const { return DVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zywx() const { return DVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zywy() const { return DVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zywz() const { return DVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zyww() const { return DVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzxx() const { return DVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzxy() const { return DVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzxz() const { return DVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzxw() const { return DVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzyx() const { return DVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzyy() const { return DVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzyz() const { return DVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzyw() const { return DVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzzx() const { return DVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzzy() const { return DVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzzz() const { return DVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzzw() const { return DVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzwx() const { return DVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzwy() const { return DVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzwz() const { return DVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zzww() const { return DVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwxx() const { return DVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwxy() const { return DVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwxz() const { return DVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwxw() const { return DVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwyx() const { return DVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwyy() const { return DVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwyz() const { return DVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwyw() const { return DVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwzx() const { return DVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwzy() const { return DVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwzz() const { return DVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwzw() const { return DVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwwx() const { return DVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwwy() const { return DVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwwz() const { return DVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::zwww() const { return DVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxxx() const { return DVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxxy() const { return DVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxxz() const { return DVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxxw() const { return DVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxyx() const { return DVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxyy() const { return DVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxyz() const { return DVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxyw() const { return DVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxzx() const { return DVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxzy() const { return DVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxzz() const { return DVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxzw() const { return DVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxwx() const { return DVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxwy() const { return DVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxwz() const { return DVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wxww() const { return DVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyxx() const { return DVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyxy() const { return DVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyxz() const { return DVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyxw() const { return DVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyyx() const { return DVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyyy() const { return DVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyyz() const { return DVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyyw() const { return DVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyzx() const { return DVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyzy() const { return DVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyzz() const { return DVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyzw() const { return DVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wywx() const { return DVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wywy() const { return DVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wywz() const { return DVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wyww() const { return DVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzxx() const { return DVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzxy() const { return DVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzxz() const { return DVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzxw() const { return DVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzyx() const { return DVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzyy() const { return DVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzyz() const { return DVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzyw() const { return DVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzzx() const { return DVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzzy() const { return DVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzzz() const { return DVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzzw() const { return DVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzwx() const { return DVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzwy() const { return DVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzwz() const { return DVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wzww() const { return DVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwxx() const { return DVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwxy() const { return DVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwxz() const { return DVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwxw() const { return DVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwyx() const { return DVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwyy() const { return DVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwyz() const { return DVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwyw() const { return DVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwzx() const { return DVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwzy() const { return DVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwzz() const { return DVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwzw() const { return DVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwwx() const { return DVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwwy() const { return DVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwwz() const { return DVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::DVec4 Onyx::Math::DVec4::wwww() const { return DVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.w); }





Onyx::Math::IVec2 Onyx::Math::IVec2::xx() const { return IVec2(m_vec.x, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec2::xy() const { return IVec2(m_vec.x, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec2::yx() const { return IVec2(m_vec.x, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec2::yy() const { return IVec2(m_vec.x, m_vec.x); }


Onyx::Math::IVec2 Onyx::Math::IVec3::xx() const { return IVec2(m_vec.x, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec3::xy() const { return IVec2(m_vec.x, m_vec.y); }
Onyx::Math::IVec2 Onyx::Math::IVec3::xz() const { return IVec2(m_vec.x, m_vec.z); }
Onyx::Math::IVec2 Onyx::Math::IVec3::yx() const { return IVec2(m_vec.y, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec3::yy() const { return IVec2(m_vec.y, m_vec.y); }
Onyx::Math::IVec2 Onyx::Math::IVec3::yz() const { return IVec2(m_vec.y, m_vec.z); }
Onyx::Math::IVec2 Onyx::Math::IVec3::zx() const { return IVec2(m_vec.z, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec3::zy() const { return IVec2(m_vec.z, m_vec.y); }
Onyx::Math::IVec2 Onyx::Math::IVec3::zz() const { return IVec2(m_vec.z, m_vec.z); }

Onyx::Math::IVec3 Onyx::Math::IVec3::xxx() const { return IVec3(m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::xxy() const { return IVec3(m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::xxz() const { return IVec3(m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec3::xyx() const { return IVec3(m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::xyy() const { return IVec3(m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::xyz() const { return IVec3(m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec3::xzx() const { return IVec3(m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::xzy() const { return IVec3(m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::xzz() const { return IVec3(m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yxx() const { return IVec3(m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yxy() const { return IVec3(m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yxz() const { return IVec3(m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yyx() const { return IVec3(m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yyy() const { return IVec3(m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yyz() const { return IVec3(m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yzx() const { return IVec3(m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yzy() const { return IVec3(m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::yzz() const { return IVec3(m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zxx() const { return IVec3(m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zxy() const { return IVec3(m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zxz() const { return IVec3(m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zyx() const { return IVec3(m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zyy() const { return IVec3(m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zyz() const { return IVec3(m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zzx() const { return IVec3(m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zzy() const { return IVec3(m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec3::zzz() const { return IVec3(m_vec.z, m_vec.z, m_vec.z); }


Onyx::Math::IVec2 Onyx::Math::IVec4::xx() const { return IVec2(m_vec.x, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec4::xy() const { return IVec2(m_vec.x, m_vec.y); }
Onyx::Math::IVec2 Onyx::Math::IVec4::xz() const { return IVec2(m_vec.x, m_vec.z); }
Onyx::Math::IVec2 Onyx::Math::IVec4::xw() const { return IVec2(m_vec.x, m_vec.w); }
Onyx::Math::IVec2 Onyx::Math::IVec4::yx() const { return IVec2(m_vec.y, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec4::yy() const { return IVec2(m_vec.y, m_vec.y); }
Onyx::Math::IVec2 Onyx::Math::IVec4::yz() const { return IVec2(m_vec.y, m_vec.z); }
Onyx::Math::IVec2 Onyx::Math::IVec4::yw() const { return IVec2(m_vec.y, m_vec.w); }
Onyx::Math::IVec2 Onyx::Math::IVec4::zx() const { return IVec2(m_vec.z, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec4::zy() const { return IVec2(m_vec.z, m_vec.y); }
Onyx::Math::IVec2 Onyx::Math::IVec4::zz() const { return IVec2(m_vec.z, m_vec.z); }
Onyx::Math::IVec2 Onyx::Math::IVec4::zw() const { return IVec2(m_vec.z, m_vec.w); }
Onyx::Math::IVec2 Onyx::Math::IVec4::wx() const { return IVec2(m_vec.w, m_vec.x); }
Onyx::Math::IVec2 Onyx::Math::IVec4::wy() const { return IVec2(m_vec.w, m_vec.y); }
Onyx::Math::IVec2 Onyx::Math::IVec4::wz() const { return IVec2(m_vec.w, m_vec.z); }
Onyx::Math::IVec2 Onyx::Math::IVec4::ww() const { return IVec2(m_vec.w, m_vec.w); }

Onyx::Math::IVec3 Onyx::Math::IVec4::xxx() const { return IVec3(m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xxy() const { return IVec3(m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xxz() const { return IVec3(m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xxw() const { return IVec3(m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xyx() const { return IVec3(m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xyy() const { return IVec3(m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xyz() const { return IVec3(m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xyw() const { return IVec3(m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xzx() const { return IVec3(m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xzy() const { return IVec3(m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xzz() const { return IVec3(m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xzw() const { return IVec3(m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xwx() const { return IVec3(m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xwy() const { return IVec3(m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xwz() const { return IVec3(m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::xww() const { return IVec3(m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yxx() const { return IVec3(m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yxy() const { return IVec3(m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yxz() const { return IVec3(m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yxw() const { return IVec3(m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yyx() const { return IVec3(m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yyy() const { return IVec3(m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yyz() const { return IVec3(m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yyw() const { return IVec3(m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yzx() const { return IVec3(m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yzy() const { return IVec3(m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yzz() const { return IVec3(m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yzw() const { return IVec3(m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::ywx() const { return IVec3(m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::ywy() const { return IVec3(m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::ywz() const { return IVec3(m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::yww() const { return IVec3(m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zxx() const { return IVec3(m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zxy() const { return IVec3(m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zxz() const { return IVec3(m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zxw() const { return IVec3(m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zyx() const { return IVec3(m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zyy() const { return IVec3(m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zyz() const { return IVec3(m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zyw() const { return IVec3(m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zzx() const { return IVec3(m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zzy() const { return IVec3(m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zzz() const { return IVec3(m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zzw() const { return IVec3(m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zwx() const { return IVec3(m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zwy() const { return IVec3(m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zwz() const { return IVec3(m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::zww() const { return IVec3(m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wxx() const { return IVec3(m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wxy() const { return IVec3(m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wxz() const { return IVec3(m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wxw() const { return IVec3(m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wyx() const { return IVec3(m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wyy() const { return IVec3(m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wyz() const { return IVec3(m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wyw() const { return IVec3(m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wzx() const { return IVec3(m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wzy() const { return IVec3(m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wzz() const { return IVec3(m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wzw() const { return IVec3(m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wwx() const { return IVec3(m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wwy() const { return IVec3(m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::IVec3 Onyx::Math::IVec4::wwz() const { return IVec3(m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::IVec3 Onyx::Math::IVec4::www() const { return IVec3(m_vec.w, m_vec.w, m_vec.w); }

Onyx::Math::IVec4 Onyx::Math::IVec4::xxxx() const { return IVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxxy() const { return IVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxxz() const { return IVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxxw() const { return IVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxyx() const { return IVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxyy() const { return IVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxyz() const { return IVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxyw() const { return IVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxzx() const { return IVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxzy() const { return IVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxzz() const { return IVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxzw() const { return IVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxwx() const { return IVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxwy() const { return IVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxwz() const { return IVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xxww() const { return IVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyxx() const { return IVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyxy() const { return IVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyxz() const { return IVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyxw() const { return IVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyyx() const { return IVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyyy() const { return IVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyyz() const { return IVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyyw() const { return IVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyzx() const { return IVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyzy() const { return IVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyzz() const { return IVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyzw() const { return IVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xywx() const { return IVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xywy() const { return IVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xywz() const { return IVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xyww() const { return IVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzxx() const { return IVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzxy() const { return IVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzxz() const { return IVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzxw() const { return IVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzyx() const { return IVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzyy() const { return IVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzyz() const { return IVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzyw() const { return IVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzzx() const { return IVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzzy() const { return IVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzzz() const { return IVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzzw() const { return IVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzwx() const { return IVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzwy() const { return IVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzwz() const { return IVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xzww() const { return IVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwxx() const { return IVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwxy() const { return IVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwxz() const { return IVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwxw() const { return IVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwyx() const { return IVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwyy() const { return IVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwyz() const { return IVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwyw() const { return IVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwzx() const { return IVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwzy() const { return IVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwzz() const { return IVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwzw() const { return IVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwwx() const { return IVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwwy() const { return IVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwwz() const { return IVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::xwww() const { return IVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxxx() const { return IVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxxy() const { return IVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxxz() const { return IVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxxw() const { return IVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxyx() const { return IVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxyy() const { return IVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxyz() const { return IVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxyw() const { return IVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxzx() const { return IVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxzy() const { return IVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxzz() const { return IVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxzw() const { return IVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxwx() const { return IVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxwy() const { return IVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxwz() const { return IVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yxww() const { return IVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyxx() const { return IVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyxy() const { return IVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyxz() const { return IVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyxw() const { return IVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyyx() const { return IVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyyy() const { return IVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyyz() const { return IVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyyw() const { return IVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyzx() const { return IVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyzy() const { return IVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyzz() const { return IVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyzw() const { return IVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yywx() const { return IVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yywy() const { return IVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yywz() const { return IVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yyww() const { return IVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzxx() const { return IVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzxy() const { return IVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzxz() const { return IVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzxw() const { return IVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzyx() const { return IVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzyy() const { return IVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzyz() const { return IVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzyw() const { return IVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzzx() const { return IVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzzy() const { return IVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzzz() const { return IVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzzw() const { return IVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzwx() const { return IVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzwy() const { return IVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzwz() const { return IVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::yzww() const { return IVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywxx() const { return IVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywxy() const { return IVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywxz() const { return IVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywxw() const { return IVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywyx() const { return IVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywyy() const { return IVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywyz() const { return IVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywyw() const { return IVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywzx() const { return IVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywzy() const { return IVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywzz() const { return IVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywzw() const { return IVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywwx() const { return IVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywwy() const { return IVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywwz() const { return IVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::ywww() const { return IVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxxx() const { return IVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxxy() const { return IVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxxz() const { return IVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxxw() const { return IVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxyx() const { return IVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxyy() const { return IVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxyz() const { return IVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxyw() const { return IVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxzx() const { return IVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxzy() const { return IVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxzz() const { return IVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxzw() const { return IVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxwx() const { return IVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxwy() const { return IVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxwz() const { return IVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zxww() const { return IVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyxx() const { return IVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyxy() const { return IVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyxz() const { return IVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyxw() const { return IVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyyx() const { return IVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyyy() const { return IVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyyz() const { return IVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyyw() const { return IVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyzx() const { return IVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyzy() const { return IVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyzz() const { return IVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyzw() const { return IVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zywx() const { return IVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zywy() const { return IVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zywz() const { return IVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zyww() const { return IVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzxx() const { return IVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzxy() const { return IVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzxz() const { return IVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzxw() const { return IVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzyx() const { return IVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzyy() const { return IVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzyz() const { return IVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzyw() const { return IVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzzx() const { return IVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzzy() const { return IVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzzz() const { return IVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzzw() const { return IVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzwx() const { return IVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzwy() const { return IVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzwz() const { return IVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zzww() const { return IVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwxx() const { return IVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwxy() const { return IVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwxz() const { return IVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwxw() const { return IVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwyx() const { return IVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwyy() const { return IVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwyz() const { return IVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwyw() const { return IVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwzx() const { return IVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwzy() const { return IVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwzz() const { return IVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwzw() const { return IVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwwx() const { return IVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwwy() const { return IVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwwz() const { return IVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::zwww() const { return IVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxxx() const { return IVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxxy() const { return IVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxxz() const { return IVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxxw() const { return IVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxyx() const { return IVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxyy() const { return IVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxyz() const { return IVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxyw() const { return IVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxzx() const { return IVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxzy() const { return IVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxzz() const { return IVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxzw() const { return IVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxwx() const { return IVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxwy() const { return IVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxwz() const { return IVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wxww() const { return IVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyxx() const { return IVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyxy() const { return IVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyxz() const { return IVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyxw() const { return IVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyyx() const { return IVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyyy() const { return IVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyyz() const { return IVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyyw() const { return IVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyzx() const { return IVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyzy() const { return IVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyzz() const { return IVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyzw() const { return IVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wywx() const { return IVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wywy() const { return IVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wywz() const { return IVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wyww() const { return IVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzxx() const { return IVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzxy() const { return IVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzxz() const { return IVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzxw() const { return IVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzyx() const { return IVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzyy() const { return IVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzyz() const { return IVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzyw() const { return IVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzzx() const { return IVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzzy() const { return IVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzzz() const { return IVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzzw() const { return IVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzwx() const { return IVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzwy() const { return IVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzwz() const { return IVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wzww() const { return IVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwxx() const { return IVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwxy() const { return IVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwxz() const { return IVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwxw() const { return IVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwyx() const { return IVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwyy() const { return IVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwyz() const { return IVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwyw() const { return IVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwzx() const { return IVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwzy() const { return IVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwzz() const { return IVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwzw() const { return IVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwwx() const { return IVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwwy() const { return IVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwwz() const { return IVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::IVec4 Onyx::Math::IVec4::wwww() const { return IVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.w); }





Onyx::Math::UVec2 Onyx::Math::UVec2::xx() const { return UVec2(m_vec.x, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec2::xy() const { return UVec2(m_vec.x, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec2::yx() const { return UVec2(m_vec.x, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec2::yy() const { return UVec2(m_vec.x, m_vec.x); }


Onyx::Math::UVec2 Onyx::Math::UVec3::xx() const { return UVec2(m_vec.x, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec3::xy() const { return UVec2(m_vec.x, m_vec.y); }
Onyx::Math::UVec2 Onyx::Math::UVec3::xz() const { return UVec2(m_vec.x, m_vec.z); }
Onyx::Math::UVec2 Onyx::Math::UVec3::yx() const { return UVec2(m_vec.y, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec3::yy() const { return UVec2(m_vec.y, m_vec.y); }
Onyx::Math::UVec2 Onyx::Math::UVec3::yz() const { return UVec2(m_vec.y, m_vec.z); }
Onyx::Math::UVec2 Onyx::Math::UVec3::zx() const { return UVec2(m_vec.z, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec3::zy() const { return UVec2(m_vec.z, m_vec.y); }
Onyx::Math::UVec2 Onyx::Math::UVec3::zz() const { return UVec2(m_vec.z, m_vec.z); }

Onyx::Math::UVec3 Onyx::Math::UVec3::xxx() const { return UVec3(m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::xxy() const { return UVec3(m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::xxz() const { return UVec3(m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec3::xyx() const { return UVec3(m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::xyy() const { return UVec3(m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::xyz() const { return UVec3(m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec3::xzx() const { return UVec3(m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::xzy() const { return UVec3(m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::xzz() const { return UVec3(m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yxx() const { return UVec3(m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yxy() const { return UVec3(m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yxz() const { return UVec3(m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yyx() const { return UVec3(m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yyy() const { return UVec3(m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yyz() const { return UVec3(m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yzx() const { return UVec3(m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yzy() const { return UVec3(m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::yzz() const { return UVec3(m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zxx() const { return UVec3(m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zxy() const { return UVec3(m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zxz() const { return UVec3(m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zyx() const { return UVec3(m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zyy() const { return UVec3(m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zyz() const { return UVec3(m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zzx() const { return UVec3(m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zzy() const { return UVec3(m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec3::zzz() const { return UVec3(m_vec.z, m_vec.z, m_vec.z); }


Onyx::Math::UVec2 Onyx::Math::UVec4::xx() const { return UVec2(m_vec.x, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec4::xy() const { return UVec2(m_vec.x, m_vec.y); }
Onyx::Math::UVec2 Onyx::Math::UVec4::xz() const { return UVec2(m_vec.x, m_vec.z); }
Onyx::Math::UVec2 Onyx::Math::UVec4::xw() const { return UVec2(m_vec.x, m_vec.w); }
Onyx::Math::UVec2 Onyx::Math::UVec4::yx() const { return UVec2(m_vec.y, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec4::yy() const { return UVec2(m_vec.y, m_vec.y); }
Onyx::Math::UVec2 Onyx::Math::UVec4::yz() const { return UVec2(m_vec.y, m_vec.z); }
Onyx::Math::UVec2 Onyx::Math::UVec4::yw() const { return UVec2(m_vec.y, m_vec.w); }
Onyx::Math::UVec2 Onyx::Math::UVec4::zx() const { return UVec2(m_vec.z, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec4::zy() const { return UVec2(m_vec.z, m_vec.y); }
Onyx::Math::UVec2 Onyx::Math::UVec4::zz() const { return UVec2(m_vec.z, m_vec.z); }
Onyx::Math::UVec2 Onyx::Math::UVec4::zw() const { return UVec2(m_vec.z, m_vec.w); }
Onyx::Math::UVec2 Onyx::Math::UVec4::wx() const { return UVec2(m_vec.w, m_vec.x); }
Onyx::Math::UVec2 Onyx::Math::UVec4::wy() const { return UVec2(m_vec.w, m_vec.y); }
Onyx::Math::UVec2 Onyx::Math::UVec4::wz() const { return UVec2(m_vec.w, m_vec.z); }
Onyx::Math::UVec2 Onyx::Math::UVec4::ww() const { return UVec2(m_vec.w, m_vec.w); }

Onyx::Math::UVec3 Onyx::Math::UVec4::xxx() const { return UVec3(m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xxy() const { return UVec3(m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xxz() const { return UVec3(m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xxw() const { return UVec3(m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xyx() const { return UVec3(m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xyy() const { return UVec3(m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xyz() const { return UVec3(m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xyw() const { return UVec3(m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xzx() const { return UVec3(m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xzy() const { return UVec3(m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xzz() const { return UVec3(m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xzw() const { return UVec3(m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xwx() const { return UVec3(m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xwy() const { return UVec3(m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xwz() const { return UVec3(m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::xww() const { return UVec3(m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yxx() const { return UVec3(m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yxy() const { return UVec3(m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yxz() const { return UVec3(m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yxw() const { return UVec3(m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yyx() const { return UVec3(m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yyy() const { return UVec3(m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yyz() const { return UVec3(m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yyw() const { return UVec3(m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yzx() const { return UVec3(m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yzy() const { return UVec3(m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yzz() const { return UVec3(m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yzw() const { return UVec3(m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::ywx() const { return UVec3(m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::ywy() const { return UVec3(m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::ywz() const { return UVec3(m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::yww() const { return UVec3(m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zxx() const { return UVec3(m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zxy() const { return UVec3(m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zxz() const { return UVec3(m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zxw() const { return UVec3(m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zyx() const { return UVec3(m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zyy() const { return UVec3(m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zyz() const { return UVec3(m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zyw() const { return UVec3(m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zzx() const { return UVec3(m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zzy() const { return UVec3(m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zzz() const { return UVec3(m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zzw() const { return UVec3(m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zwx() const { return UVec3(m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zwy() const { return UVec3(m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zwz() const { return UVec3(m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::zww() const { return UVec3(m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wxx() const { return UVec3(m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wxy() const { return UVec3(m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wxz() const { return UVec3(m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wxw() const { return UVec3(m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wyx() const { return UVec3(m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wyy() const { return UVec3(m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wyz() const { return UVec3(m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wyw() const { return UVec3(m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wzx() const { return UVec3(m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wzy() const { return UVec3(m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wzz() const { return UVec3(m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wzw() const { return UVec3(m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wwx() const { return UVec3(m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wwy() const { return UVec3(m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::UVec3 Onyx::Math::UVec4::wwz() const { return UVec3(m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::UVec3 Onyx::Math::UVec4::www() const { return UVec3(m_vec.w, m_vec.w, m_vec.w); }

Onyx::Math::UVec4 Onyx::Math::UVec4::xxxx() const { return UVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxxy() const { return UVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxxz() const { return UVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxxw() const { return UVec4(m_vec.x, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxyx() const { return UVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxyy() const { return UVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxyz() const { return UVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxyw() const { return UVec4(m_vec.x, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxzx() const { return UVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxzy() const { return UVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxzz() const { return UVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxzw() const { return UVec4(m_vec.x, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxwx() const { return UVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxwy() const { return UVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxwz() const { return UVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xxww() const { return UVec4(m_vec.x, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyxx() const { return UVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyxy() const { return UVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyxz() const { return UVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyxw() const { return UVec4(m_vec.x, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyyx() const { return UVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyyy() const { return UVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyyz() const { return UVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyyw() const { return UVec4(m_vec.x, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyzx() const { return UVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyzy() const { return UVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyzz() const { return UVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyzw() const { return UVec4(m_vec.x, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xywx() const { return UVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xywy() const { return UVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xywz() const { return UVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xyww() const { return UVec4(m_vec.x, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzxx() const { return UVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzxy() const { return UVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzxz() const { return UVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzxw() const { return UVec4(m_vec.x, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzyx() const { return UVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzyy() const { return UVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzyz() const { return UVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzyw() const { return UVec4(m_vec.x, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzzx() const { return UVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzzy() const { return UVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzzz() const { return UVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzzw() const { return UVec4(m_vec.x, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzwx() const { return UVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzwy() const { return UVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzwz() const { return UVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xzww() const { return UVec4(m_vec.x, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwxx() const { return UVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwxy() const { return UVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwxz() const { return UVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwxw() const { return UVec4(m_vec.x, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwyx() const { return UVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwyy() const { return UVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwyz() const { return UVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwyw() const { return UVec4(m_vec.x, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwzx() const { return UVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwzy() const { return UVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwzz() const { return UVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwzw() const { return UVec4(m_vec.x, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwwx() const { return UVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwwy() const { return UVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwwz() const { return UVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::xwww() const { return UVec4(m_vec.x, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxxx() const { return UVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxxy() const { return UVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxxz() const { return UVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxxw() const { return UVec4(m_vec.y, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxyx() const { return UVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxyy() const { return UVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxyz() const { return UVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxyw() const { return UVec4(m_vec.y, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxzx() const { return UVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxzy() const { return UVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxzz() const { return UVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxzw() const { return UVec4(m_vec.y, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxwx() const { return UVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxwy() const { return UVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxwz() const { return UVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yxww() const { return UVec4(m_vec.y, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyxx() const { return UVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyxy() const { return UVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyxz() const { return UVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyxw() const { return UVec4(m_vec.y, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyyx() const { return UVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyyy() const { return UVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyyz() const { return UVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyyw() const { return UVec4(m_vec.y, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyzx() const { return UVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyzy() const { return UVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyzz() const { return UVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyzw() const { return UVec4(m_vec.y, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yywx() const { return UVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yywy() const { return UVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yywz() const { return UVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yyww() const { return UVec4(m_vec.y, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzxx() const { return UVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzxy() const { return UVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzxz() const { return UVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzxw() const { return UVec4(m_vec.y, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzyx() const { return UVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzyy() const { return UVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzyz() const { return UVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzyw() const { return UVec4(m_vec.y, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzzx() const { return UVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzzy() const { return UVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzzz() const { return UVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzzw() const { return UVec4(m_vec.y, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzwx() const { return UVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzwy() const { return UVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzwz() const { return UVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::yzww() const { return UVec4(m_vec.y, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywxx() const { return UVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywxy() const { return UVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywxz() const { return UVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywxw() const { return UVec4(m_vec.y, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywyx() const { return UVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywyy() const { return UVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywyz() const { return UVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywyw() const { return UVec4(m_vec.y, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywzx() const { return UVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywzy() const { return UVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywzz() const { return UVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywzw() const { return UVec4(m_vec.y, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywwx() const { return UVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywwy() const { return UVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywwz() const { return UVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::ywww() const { return UVec4(m_vec.y, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxxx() const { return UVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxxy() const { return UVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxxz() const { return UVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxxw() const { return UVec4(m_vec.z, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxyx() const { return UVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxyy() const { return UVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxyz() const { return UVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxyw() const { return UVec4(m_vec.z, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxzx() const { return UVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxzy() const { return UVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxzz() const { return UVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxzw() const { return UVec4(m_vec.z, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxwx() const { return UVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxwy() const { return UVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxwz() const { return UVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zxww() const { return UVec4(m_vec.z, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyxx() const { return UVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyxy() const { return UVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyxz() const { return UVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyxw() const { return UVec4(m_vec.z, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyyx() const { return UVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyyy() const { return UVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyyz() const { return UVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyyw() const { return UVec4(m_vec.z, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyzx() const { return UVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyzy() const { return UVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyzz() const { return UVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyzw() const { return UVec4(m_vec.z, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zywx() const { return UVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zywy() const { return UVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zywz() const { return UVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zyww() const { return UVec4(m_vec.z, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzxx() const { return UVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzxy() const { return UVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzxz() const { return UVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzxw() const { return UVec4(m_vec.z, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzyx() const { return UVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzyy() const { return UVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzyz() const { return UVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzyw() const { return UVec4(m_vec.z, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzzx() const { return UVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzzy() const { return UVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzzz() const { return UVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzzw() const { return UVec4(m_vec.z, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzwx() const { return UVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzwy() const { return UVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzwz() const { return UVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zzww() const { return UVec4(m_vec.z, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwxx() const { return UVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwxy() const { return UVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwxz() const { return UVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwxw() const { return UVec4(m_vec.z, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwyx() const { return UVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwyy() const { return UVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwyz() const { return UVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwyw() const { return UVec4(m_vec.z, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwzx() const { return UVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwzy() const { return UVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwzz() const { return UVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwzw() const { return UVec4(m_vec.z, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwwx() const { return UVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwwy() const { return UVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwwz() const { return UVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::zwww() const { return UVec4(m_vec.z, m_vec.w, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxxx() const { return UVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxxy() const { return UVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxxz() const { return UVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxxw() const { return UVec4(m_vec.w, m_vec.x, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxyx() const { return UVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxyy() const { return UVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxyz() const { return UVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxyw() const { return UVec4(m_vec.w, m_vec.x, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxzx() const { return UVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxzy() const { return UVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxzz() const { return UVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxzw() const { return UVec4(m_vec.w, m_vec.x, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxwx() const { return UVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxwy() const { return UVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxwz() const { return UVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wxww() const { return UVec4(m_vec.w, m_vec.x, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyxx() const { return UVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyxy() const { return UVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyxz() const { return UVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyxw() const { return UVec4(m_vec.w, m_vec.y, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyyx() const { return UVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyyy() const { return UVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyyz() const { return UVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyyw() const { return UVec4(m_vec.w, m_vec.y, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyzx() const { return UVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyzy() const { return UVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyzz() const { return UVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyzw() const { return UVec4(m_vec.w, m_vec.y, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wywx() const { return UVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wywy() const { return UVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wywz() const { return UVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wyww() const { return UVec4(m_vec.w, m_vec.y, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzxx() const { return UVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzxy() const { return UVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzxz() const { return UVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzxw() const { return UVec4(m_vec.w, m_vec.z, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzyx() const { return UVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzyy() const { return UVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzyz() const { return UVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzyw() const { return UVec4(m_vec.w, m_vec.z, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzzx() const { return UVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzzy() const { return UVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzzz() const { return UVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzzw() const { return UVec4(m_vec.w, m_vec.z, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzwx() const { return UVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzwy() const { return UVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzwz() const { return UVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wzww() const { return UVec4(m_vec.w, m_vec.z, m_vec.w, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwxx() const { return UVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwxy() const { return UVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwxz() const { return UVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwxw() const { return UVec4(m_vec.w, m_vec.w, m_vec.x, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwyx() const { return UVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwyy() const { return UVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwyz() const { return UVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwyw() const { return UVec4(m_vec.w, m_vec.w, m_vec.y, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwzx() const { return UVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwzy() const { return UVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwzz() const { return UVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwzw() const { return UVec4(m_vec.w, m_vec.w, m_vec.z, m_vec.w); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwwx() const { return UVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.x); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwwy() const { return UVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.y); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwwz() const { return UVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.z); }
Onyx::Math::UVec4 Onyx::Math::UVec4::wwww() const { return UVec4(m_vec.w, m_vec.w, m_vec.w, m_vec.w); }
