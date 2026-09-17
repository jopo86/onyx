#include "math_wrappers.h"

/*
	I would like to give a huge thanks to:
	 - ChatGPT
	 - Select all occurences keyboard shortcut
 */

onyx::math::Vec2 onyx::math::Vec2::xx() const { return Vec2(this->vec.x, this->vec.x); }
onyx::math::Vec2 onyx::math::Vec2::xy() const { return Vec2(this->vec.x, this->vec.x); }
onyx::math::Vec2 onyx::math::Vec2::yx() const { return Vec2(this->vec.x, this->vec.x); }
onyx::math::Vec2 onyx::math::Vec2::yy() const { return Vec2(this->vec.x, this->vec.x); }


onyx::math::Vec2 onyx::math::Vec3::xx() const { return Vec2(this->vec.x, this->vec.x); }
onyx::math::Vec2 onyx::math::Vec3::xy() const { return Vec2(this->vec.x, this->vec.y); }
onyx::math::Vec2 onyx::math::Vec3::xz() const { return Vec2(this->vec.x, this->vec.z); }
onyx::math::Vec2 onyx::math::Vec3::yx() const { return Vec2(this->vec.y, this->vec.x); }
onyx::math::Vec2 onyx::math::Vec3::yy() const { return Vec2(this->vec.y, this->vec.y); }
onyx::math::Vec2 onyx::math::Vec3::yz() const { return Vec2(this->vec.y, this->vec.z); }
onyx::math::Vec2 onyx::math::Vec3::zx() const { return Vec2(this->vec.z, this->vec.x); }
onyx::math::Vec2 onyx::math::Vec3::zy() const { return Vec2(this->vec.z, this->vec.y); }
onyx::math::Vec2 onyx::math::Vec3::zz() const { return Vec2(this->vec.z, this->vec.z); }

onyx::math::Vec3 onyx::math::Vec3::xxx() const { return Vec3(this->vec.x, this->vec.x, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec3::xxy() const { return Vec3(this->vec.x, this->vec.x, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec3::xxz() const { return Vec3(this->vec.x, this->vec.x, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec3::xyx() const { return Vec3(this->vec.x, this->vec.y, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec3::xyy() const { return Vec3(this->vec.x, this->vec.y, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec3::xyz() const { return Vec3(this->vec.x, this->vec.y, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec3::xzx() const { return Vec3(this->vec.x, this->vec.z, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec3::xzy() const { return Vec3(this->vec.x, this->vec.z, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec3::xzz() const { return Vec3(this->vec.x, this->vec.z, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec3::yxx() const { return Vec3(this->vec.y, this->vec.x, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec3::yxy() const { return Vec3(this->vec.y, this->vec.x, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec3::yxz() const { return Vec3(this->vec.y, this->vec.x, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec3::yyx() const { return Vec3(this->vec.y, this->vec.y, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec3::yyy() const { return Vec3(this->vec.y, this->vec.y, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec3::yyz() const { return Vec3(this->vec.y, this->vec.y, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec3::yzx() const { return Vec3(this->vec.y, this->vec.z, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec3::yzy() const { return Vec3(this->vec.y, this->vec.z, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec3::yzz() const { return Vec3(this->vec.y, this->vec.z, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec3::zxx() const { return Vec3(this->vec.z, this->vec.x, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec3::zxy() const { return Vec3(this->vec.z, this->vec.x, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec3::zxz() const { return Vec3(this->vec.z, this->vec.x, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec3::zyx() const { return Vec3(this->vec.z, this->vec.y, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec3::zyy() const { return Vec3(this->vec.z, this->vec.y, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec3::zyz() const { return Vec3(this->vec.z, this->vec.y, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec3::zzx() const { return Vec3(this->vec.z, this->vec.z, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec3::zzy() const { return Vec3(this->vec.z, this->vec.z, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec3::zzz() const { return Vec3(this->vec.z, this->vec.z, this->vec.z); }


onyx::math::Vec2 onyx::math::Vec4::xx() const { return Vec2(this->vec.x, this->vec.x); }
onyx::math::Vec2 onyx::math::Vec4::xy() const { return Vec2(this->vec.x, this->vec.y); }
onyx::math::Vec2 onyx::math::Vec4::xz() const { return Vec2(this->vec.x, this->vec.z); }
onyx::math::Vec2 onyx::math::Vec4::xw() const { return Vec2(this->vec.x, this->vec.w); }
onyx::math::Vec2 onyx::math::Vec4::yx() const { return Vec2(this->vec.y, this->vec.x); }
onyx::math::Vec2 onyx::math::Vec4::yy() const { return Vec2(this->vec.y, this->vec.y); }
onyx::math::Vec2 onyx::math::Vec4::yz() const { return Vec2(this->vec.y, this->vec.z); }
onyx::math::Vec2 onyx::math::Vec4::yw() const { return Vec2(this->vec.y, this->vec.w); }
onyx::math::Vec2 onyx::math::Vec4::zx() const { return Vec2(this->vec.z, this->vec.x); }
onyx::math::Vec2 onyx::math::Vec4::zy() const { return Vec2(this->vec.z, this->vec.y); }
onyx::math::Vec2 onyx::math::Vec4::zz() const { return Vec2(this->vec.z, this->vec.z); }
onyx::math::Vec2 onyx::math::Vec4::zw() const { return Vec2(this->vec.z, this->vec.w); }
onyx::math::Vec2 onyx::math::Vec4::wx() const { return Vec2(this->vec.w, this->vec.x); }
onyx::math::Vec2 onyx::math::Vec4::wy() const { return Vec2(this->vec.w, this->vec.y); }
onyx::math::Vec2 onyx::math::Vec4::wz() const { return Vec2(this->vec.w, this->vec.z); }
onyx::math::Vec2 onyx::math::Vec4::ww() const { return Vec2(this->vec.w, this->vec.w); }

onyx::math::Vec3 onyx::math::Vec4::xxx() const { return Vec3(this->vec.x, this->vec.x, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec4::xxy() const { return Vec3(this->vec.x, this->vec.x, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec4::xxz() const { return Vec3(this->vec.x, this->vec.x, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec4::xxw() const { return Vec3(this->vec.x, this->vec.x, this->vec.w); }
onyx::math::Vec3 onyx::math::Vec4::xyx() const { return Vec3(this->vec.x, this->vec.y, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec4::xyy() const { return Vec3(this->vec.x, this->vec.y, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec4::xyz() const { return Vec3(this->vec.x, this->vec.y, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec4::xyw() const { return Vec3(this->vec.x, this->vec.y, this->vec.w); }
onyx::math::Vec3 onyx::math::Vec4::xzx() const { return Vec3(this->vec.x, this->vec.z, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec4::xzy() const { return Vec3(this->vec.x, this->vec.z, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec4::xzz() const { return Vec3(this->vec.x, this->vec.z, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec4::xzw() const { return Vec3(this->vec.x, this->vec.z, this->vec.w); }
onyx::math::Vec3 onyx::math::Vec4::xwx() const { return Vec3(this->vec.x, this->vec.w, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec4::xwy() const { return Vec3(this->vec.x, this->vec.w, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec4::xwz() const { return Vec3(this->vec.x, this->vec.w, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec4::xww() const { return Vec3(this->vec.x, this->vec.w, this->vec.w); }
onyx::math::Vec3 onyx::math::Vec4::yxx() const { return Vec3(this->vec.y, this->vec.x, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec4::yxy() const { return Vec3(this->vec.y, this->vec.x, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec4::yxz() const { return Vec3(this->vec.y, this->vec.x, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec4::yxw() const { return Vec3(this->vec.y, this->vec.x, this->vec.w); }
onyx::math::Vec3 onyx::math::Vec4::yyx() const { return Vec3(this->vec.y, this->vec.y, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec4::yyy() const { return Vec3(this->vec.y, this->vec.y, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec4::yyz() const { return Vec3(this->vec.y, this->vec.y, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec4::yyw() const { return Vec3(this->vec.y, this->vec.y, this->vec.w); }
onyx::math::Vec3 onyx::math::Vec4::yzx() const { return Vec3(this->vec.y, this->vec.z, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec4::yzy() const { return Vec3(this->vec.y, this->vec.z, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec4::yzz() const { return Vec3(this->vec.y, this->vec.z, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec4::yzw() const { return Vec3(this->vec.y, this->vec.z, this->vec.w); }
onyx::math::Vec3 onyx::math::Vec4::ywx() const { return Vec3(this->vec.y, this->vec.w, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec4::ywy() const { return Vec3(this->vec.y, this->vec.w, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec4::ywz() const { return Vec3(this->vec.y, this->vec.w, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec4::yww() const { return Vec3(this->vec.y, this->vec.w, this->vec.w); }
onyx::math::Vec3 onyx::math::Vec4::zxx() const { return Vec3(this->vec.z, this->vec.x, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec4::zxy() const { return Vec3(this->vec.z, this->vec.x, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec4::zxz() const { return Vec3(this->vec.z, this->vec.x, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec4::zxw() const { return Vec3(this->vec.z, this->vec.x, this->vec.w); }
onyx::math::Vec3 onyx::math::Vec4::zyx() const { return Vec3(this->vec.z, this->vec.y, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec4::zyy() const { return Vec3(this->vec.z, this->vec.y, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec4::zyz() const { return Vec3(this->vec.z, this->vec.y, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec4::zyw() const { return Vec3(this->vec.z, this->vec.y, this->vec.w); }
onyx::math::Vec3 onyx::math::Vec4::zzx() const { return Vec3(this->vec.z, this->vec.z, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec4::zzy() const { return Vec3(this->vec.z, this->vec.z, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec4::zzz() const { return Vec3(this->vec.z, this->vec.z, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec4::zzw() const { return Vec3(this->vec.z, this->vec.z, this->vec.w); }
onyx::math::Vec3 onyx::math::Vec4::zwx() const { return Vec3(this->vec.z, this->vec.w, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec4::zwy() const { return Vec3(this->vec.z, this->vec.w, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec4::zwz() const { return Vec3(this->vec.z, this->vec.w, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec4::zww() const { return Vec3(this->vec.z, this->vec.w, this->vec.w); }
onyx::math::Vec3 onyx::math::Vec4::wxx() const { return Vec3(this->vec.w, this->vec.x, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec4::wxy() const { return Vec3(this->vec.w, this->vec.x, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec4::wxz() const { return Vec3(this->vec.w, this->vec.x, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec4::wxw() const { return Vec3(this->vec.w, this->vec.x, this->vec.w); }
onyx::math::Vec3 onyx::math::Vec4::wyx() const { return Vec3(this->vec.w, this->vec.y, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec4::wyy() const { return Vec3(this->vec.w, this->vec.y, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec4::wyz() const { return Vec3(this->vec.w, this->vec.y, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec4::wyw() const { return Vec3(this->vec.w, this->vec.y, this->vec.w); }
onyx::math::Vec3 onyx::math::Vec4::wzx() const { return Vec3(this->vec.w, this->vec.z, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec4::wzy() const { return Vec3(this->vec.w, this->vec.z, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec4::wzz() const { return Vec3(this->vec.w, this->vec.z, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec4::wzw() const { return Vec3(this->vec.w, this->vec.z, this->vec.w); }
onyx::math::Vec3 onyx::math::Vec4::wwx() const { return Vec3(this->vec.w, this->vec.w, this->vec.x); }
onyx::math::Vec3 onyx::math::Vec4::wwy() const { return Vec3(this->vec.w, this->vec.w, this->vec.y); }
onyx::math::Vec3 onyx::math::Vec4::wwz() const { return Vec3(this->vec.w, this->vec.w, this->vec.z); }
onyx::math::Vec3 onyx::math::Vec4::www() const { return Vec3(this->vec.w, this->vec.w, this->vec.w); }

onyx::math::Vec4 onyx::math::Vec4::xxxx() const { return Vec4(this->vec.x, this->vec.x, this->vec.x, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::xxxy() const { return Vec4(this->vec.x, this->vec.x, this->vec.x, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::xxxz() const { return Vec4(this->vec.x, this->vec.x, this->vec.x, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::xxxw() const { return Vec4(this->vec.x, this->vec.x, this->vec.x, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::xxyx() const { return Vec4(this->vec.x, this->vec.x, this->vec.y, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::xxyy() const { return Vec4(this->vec.x, this->vec.x, this->vec.y, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::xxyz() const { return Vec4(this->vec.x, this->vec.x, this->vec.y, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::xxyw() const { return Vec4(this->vec.x, this->vec.x, this->vec.y, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::xxzx() const { return Vec4(this->vec.x, this->vec.x, this->vec.z, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::xxzy() const { return Vec4(this->vec.x, this->vec.x, this->vec.z, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::xxzz() const { return Vec4(this->vec.x, this->vec.x, this->vec.z, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::xxzw() const { return Vec4(this->vec.x, this->vec.x, this->vec.z, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::xxwx() const { return Vec4(this->vec.x, this->vec.x, this->vec.w, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::xxwy() const { return Vec4(this->vec.x, this->vec.x, this->vec.w, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::xxwz() const { return Vec4(this->vec.x, this->vec.x, this->vec.w, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::xxww() const { return Vec4(this->vec.x, this->vec.x, this->vec.w, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::xyxx() const { return Vec4(this->vec.x, this->vec.y, this->vec.x, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::xyxy() const { return Vec4(this->vec.x, this->vec.y, this->vec.x, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::xyxz() const { return Vec4(this->vec.x, this->vec.y, this->vec.x, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::xyxw() const { return Vec4(this->vec.x, this->vec.y, this->vec.x, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::xyyx() const { return Vec4(this->vec.x, this->vec.y, this->vec.y, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::xyyy() const { return Vec4(this->vec.x, this->vec.y, this->vec.y, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::xyyz() const { return Vec4(this->vec.x, this->vec.y, this->vec.y, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::xyyw() const { return Vec4(this->vec.x, this->vec.y, this->vec.y, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::xyzx() const { return Vec4(this->vec.x, this->vec.y, this->vec.z, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::xyzy() const { return Vec4(this->vec.x, this->vec.y, this->vec.z, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::xyzz() const { return Vec4(this->vec.x, this->vec.y, this->vec.z, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::xyzw() const { return Vec4(this->vec.x, this->vec.y, this->vec.z, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::xywx() const { return Vec4(this->vec.x, this->vec.y, this->vec.w, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::xywy() const { return Vec4(this->vec.x, this->vec.y, this->vec.w, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::xywz() const { return Vec4(this->vec.x, this->vec.y, this->vec.w, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::xyww() const { return Vec4(this->vec.x, this->vec.y, this->vec.w, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::xzxx() const { return Vec4(this->vec.x, this->vec.z, this->vec.x, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::xzxy() const { return Vec4(this->vec.x, this->vec.z, this->vec.x, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::xzxz() const { return Vec4(this->vec.x, this->vec.z, this->vec.x, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::xzxw() const { return Vec4(this->vec.x, this->vec.z, this->vec.x, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::xzyx() const { return Vec4(this->vec.x, this->vec.z, this->vec.y, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::xzyy() const { return Vec4(this->vec.x, this->vec.z, this->vec.y, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::xzyz() const { return Vec4(this->vec.x, this->vec.z, this->vec.y, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::xzyw() const { return Vec4(this->vec.x, this->vec.z, this->vec.y, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::xzzx() const { return Vec4(this->vec.x, this->vec.z, this->vec.z, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::xzzy() const { return Vec4(this->vec.x, this->vec.z, this->vec.z, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::xzzz() const { return Vec4(this->vec.x, this->vec.z, this->vec.z, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::xzzw() const { return Vec4(this->vec.x, this->vec.z, this->vec.z, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::xzwx() const { return Vec4(this->vec.x, this->vec.z, this->vec.w, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::xzwy() const { return Vec4(this->vec.x, this->vec.z, this->vec.w, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::xzwz() const { return Vec4(this->vec.x, this->vec.z, this->vec.w, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::xzww() const { return Vec4(this->vec.x, this->vec.z, this->vec.w, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::xwxx() const { return Vec4(this->vec.x, this->vec.w, this->vec.x, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::xwxy() const { return Vec4(this->vec.x, this->vec.w, this->vec.x, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::xwxz() const { return Vec4(this->vec.x, this->vec.w, this->vec.x, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::xwxw() const { return Vec4(this->vec.x, this->vec.w, this->vec.x, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::xwyx() const { return Vec4(this->vec.x, this->vec.w, this->vec.y, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::xwyy() const { return Vec4(this->vec.x, this->vec.w, this->vec.y, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::xwyz() const { return Vec4(this->vec.x, this->vec.w, this->vec.y, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::xwyw() const { return Vec4(this->vec.x, this->vec.w, this->vec.y, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::xwzx() const { return Vec4(this->vec.x, this->vec.w, this->vec.z, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::xwzy() const { return Vec4(this->vec.x, this->vec.w, this->vec.z, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::xwzz() const { return Vec4(this->vec.x, this->vec.w, this->vec.z, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::xwzw() const { return Vec4(this->vec.x, this->vec.w, this->vec.z, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::xwwx() const { return Vec4(this->vec.x, this->vec.w, this->vec.w, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::xwwy() const { return Vec4(this->vec.x, this->vec.w, this->vec.w, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::xwwz() const { return Vec4(this->vec.x, this->vec.w, this->vec.w, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::xwww() const { return Vec4(this->vec.x, this->vec.w, this->vec.w, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::yxxx() const { return Vec4(this->vec.y, this->vec.x, this->vec.x, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::yxxy() const { return Vec4(this->vec.y, this->vec.x, this->vec.x, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::yxxz() const { return Vec4(this->vec.y, this->vec.x, this->vec.x, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::yxxw() const { return Vec4(this->vec.y, this->vec.x, this->vec.x, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::yxyx() const { return Vec4(this->vec.y, this->vec.x, this->vec.y, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::yxyy() const { return Vec4(this->vec.y, this->vec.x, this->vec.y, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::yxyz() const { return Vec4(this->vec.y, this->vec.x, this->vec.y, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::yxyw() const { return Vec4(this->vec.y, this->vec.x, this->vec.y, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::yxzx() const { return Vec4(this->vec.y, this->vec.x, this->vec.z, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::yxzy() const { return Vec4(this->vec.y, this->vec.x, this->vec.z, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::yxzz() const { return Vec4(this->vec.y, this->vec.x, this->vec.z, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::yxzw() const { return Vec4(this->vec.y, this->vec.x, this->vec.z, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::yxwx() const { return Vec4(this->vec.y, this->vec.x, this->vec.w, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::yxwy() const { return Vec4(this->vec.y, this->vec.x, this->vec.w, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::yxwz() const { return Vec4(this->vec.y, this->vec.x, this->vec.w, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::yxww() const { return Vec4(this->vec.y, this->vec.x, this->vec.w, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::yyxx() const { return Vec4(this->vec.y, this->vec.y, this->vec.x, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::yyxy() const { return Vec4(this->vec.y, this->vec.y, this->vec.x, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::yyxz() const { return Vec4(this->vec.y, this->vec.y, this->vec.x, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::yyxw() const { return Vec4(this->vec.y, this->vec.y, this->vec.x, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::yyyx() const { return Vec4(this->vec.y, this->vec.y, this->vec.y, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::yyyy() const { return Vec4(this->vec.y, this->vec.y, this->vec.y, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::yyyz() const { return Vec4(this->vec.y, this->vec.y, this->vec.y, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::yyyw() const { return Vec4(this->vec.y, this->vec.y, this->vec.y, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::yyzx() const { return Vec4(this->vec.y, this->vec.y, this->vec.z, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::yyzy() const { return Vec4(this->vec.y, this->vec.y, this->vec.z, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::yyzz() const { return Vec4(this->vec.y, this->vec.y, this->vec.z, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::yyzw() const { return Vec4(this->vec.y, this->vec.y, this->vec.z, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::yywx() const { return Vec4(this->vec.y, this->vec.y, this->vec.w, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::yywy() const { return Vec4(this->vec.y, this->vec.y, this->vec.w, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::yywz() const { return Vec4(this->vec.y, this->vec.y, this->vec.w, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::yyww() const { return Vec4(this->vec.y, this->vec.y, this->vec.w, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::yzxx() const { return Vec4(this->vec.y, this->vec.z, this->vec.x, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::yzxy() const { return Vec4(this->vec.y, this->vec.z, this->vec.x, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::yzxz() const { return Vec4(this->vec.y, this->vec.z, this->vec.x, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::yzxw() const { return Vec4(this->vec.y, this->vec.z, this->vec.x, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::yzyx() const { return Vec4(this->vec.y, this->vec.z, this->vec.y, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::yzyy() const { return Vec4(this->vec.y, this->vec.z, this->vec.y, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::yzyz() const { return Vec4(this->vec.y, this->vec.z, this->vec.y, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::yzyw() const { return Vec4(this->vec.y, this->vec.z, this->vec.y, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::yzzx() const { return Vec4(this->vec.y, this->vec.z, this->vec.z, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::yzzy() const { return Vec4(this->vec.y, this->vec.z, this->vec.z, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::yzzz() const { return Vec4(this->vec.y, this->vec.z, this->vec.z, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::yzzw() const { return Vec4(this->vec.y, this->vec.z, this->vec.z, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::yzwx() const { return Vec4(this->vec.y, this->vec.z, this->vec.w, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::yzwy() const { return Vec4(this->vec.y, this->vec.z, this->vec.w, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::yzwz() const { return Vec4(this->vec.y, this->vec.z, this->vec.w, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::yzww() const { return Vec4(this->vec.y, this->vec.z, this->vec.w, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::ywxx() const { return Vec4(this->vec.y, this->vec.w, this->vec.x, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::ywxy() const { return Vec4(this->vec.y, this->vec.w, this->vec.x, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::ywxz() const { return Vec4(this->vec.y, this->vec.w, this->vec.x, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::ywxw() const { return Vec4(this->vec.y, this->vec.w, this->vec.x, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::ywyx() const { return Vec4(this->vec.y, this->vec.w, this->vec.y, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::ywyy() const { return Vec4(this->vec.y, this->vec.w, this->vec.y, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::ywyz() const { return Vec4(this->vec.y, this->vec.w, this->vec.y, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::ywyw() const { return Vec4(this->vec.y, this->vec.w, this->vec.y, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::ywzx() const { return Vec4(this->vec.y, this->vec.w, this->vec.z, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::ywzy() const { return Vec4(this->vec.y, this->vec.w, this->vec.z, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::ywzz() const { return Vec4(this->vec.y, this->vec.w, this->vec.z, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::ywzw() const { return Vec4(this->vec.y, this->vec.w, this->vec.z, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::ywwx() const { return Vec4(this->vec.y, this->vec.w, this->vec.w, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::ywwy() const { return Vec4(this->vec.y, this->vec.w, this->vec.w, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::ywwz() const { return Vec4(this->vec.y, this->vec.w, this->vec.w, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::ywww() const { return Vec4(this->vec.y, this->vec.w, this->vec.w, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::zxxx() const { return Vec4(this->vec.z, this->vec.x, this->vec.x, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::zxxy() const { return Vec4(this->vec.z, this->vec.x, this->vec.x, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::zxxz() const { return Vec4(this->vec.z, this->vec.x, this->vec.x, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::zxxw() const { return Vec4(this->vec.z, this->vec.x, this->vec.x, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::zxyx() const { return Vec4(this->vec.z, this->vec.x, this->vec.y, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::zxyy() const { return Vec4(this->vec.z, this->vec.x, this->vec.y, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::zxyz() const { return Vec4(this->vec.z, this->vec.x, this->vec.y, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::zxyw() const { return Vec4(this->vec.z, this->vec.x, this->vec.y, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::zxzx() const { return Vec4(this->vec.z, this->vec.x, this->vec.z, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::zxzy() const { return Vec4(this->vec.z, this->vec.x, this->vec.z, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::zxzz() const { return Vec4(this->vec.z, this->vec.x, this->vec.z, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::zxzw() const { return Vec4(this->vec.z, this->vec.x, this->vec.z, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::zxwx() const { return Vec4(this->vec.z, this->vec.x, this->vec.w, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::zxwy() const { return Vec4(this->vec.z, this->vec.x, this->vec.w, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::zxwz() const { return Vec4(this->vec.z, this->vec.x, this->vec.w, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::zxww() const { return Vec4(this->vec.z, this->vec.x, this->vec.w, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::zyxx() const { return Vec4(this->vec.z, this->vec.y, this->vec.x, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::zyxy() const { return Vec4(this->vec.z, this->vec.y, this->vec.x, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::zyxz() const { return Vec4(this->vec.z, this->vec.y, this->vec.x, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::zyxw() const { return Vec4(this->vec.z, this->vec.y, this->vec.x, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::zyyx() const { return Vec4(this->vec.z, this->vec.y, this->vec.y, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::zyyy() const { return Vec4(this->vec.z, this->vec.y, this->vec.y, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::zyyz() const { return Vec4(this->vec.z, this->vec.y, this->vec.y, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::zyyw() const { return Vec4(this->vec.z, this->vec.y, this->vec.y, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::zyzx() const { return Vec4(this->vec.z, this->vec.y, this->vec.z, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::zyzy() const { return Vec4(this->vec.z, this->vec.y, this->vec.z, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::zyzz() const { return Vec4(this->vec.z, this->vec.y, this->vec.z, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::zyzw() const { return Vec4(this->vec.z, this->vec.y, this->vec.z, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::zywx() const { return Vec4(this->vec.z, this->vec.y, this->vec.w, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::zywy() const { return Vec4(this->vec.z, this->vec.y, this->vec.w, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::zywz() const { return Vec4(this->vec.z, this->vec.y, this->vec.w, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::zyww() const { return Vec4(this->vec.z, this->vec.y, this->vec.w, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::zzxx() const { return Vec4(this->vec.z, this->vec.z, this->vec.x, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::zzxy() const { return Vec4(this->vec.z, this->vec.z, this->vec.x, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::zzxz() const { return Vec4(this->vec.z, this->vec.z, this->vec.x, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::zzxw() const { return Vec4(this->vec.z, this->vec.z, this->vec.x, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::zzyx() const { return Vec4(this->vec.z, this->vec.z, this->vec.y, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::zzyy() const { return Vec4(this->vec.z, this->vec.z, this->vec.y, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::zzyz() const { return Vec4(this->vec.z, this->vec.z, this->vec.y, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::zzyw() const { return Vec4(this->vec.z, this->vec.z, this->vec.y, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::zzzx() const { return Vec4(this->vec.z, this->vec.z, this->vec.z, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::zzzy() const { return Vec4(this->vec.z, this->vec.z, this->vec.z, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::zzzz() const { return Vec4(this->vec.z, this->vec.z, this->vec.z, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::zzzw() const { return Vec4(this->vec.z, this->vec.z, this->vec.z, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::zzwx() const { return Vec4(this->vec.z, this->vec.z, this->vec.w, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::zzwy() const { return Vec4(this->vec.z, this->vec.z, this->vec.w, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::zzwz() const { return Vec4(this->vec.z, this->vec.z, this->vec.w, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::zzww() const { return Vec4(this->vec.z, this->vec.z, this->vec.w, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::zwxx() const { return Vec4(this->vec.z, this->vec.w, this->vec.x, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::zwxy() const { return Vec4(this->vec.z, this->vec.w, this->vec.x, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::zwxz() const { return Vec4(this->vec.z, this->vec.w, this->vec.x, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::zwxw() const { return Vec4(this->vec.z, this->vec.w, this->vec.x, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::zwyx() const { return Vec4(this->vec.z, this->vec.w, this->vec.y, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::zwyy() const { return Vec4(this->vec.z, this->vec.w, this->vec.y, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::zwyz() const { return Vec4(this->vec.z, this->vec.w, this->vec.y, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::zwyw() const { return Vec4(this->vec.z, this->vec.w, this->vec.y, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::zwzx() const { return Vec4(this->vec.z, this->vec.w, this->vec.z, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::zwzy() const { return Vec4(this->vec.z, this->vec.w, this->vec.z, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::zwzz() const { return Vec4(this->vec.z, this->vec.w, this->vec.z, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::zwzw() const { return Vec4(this->vec.z, this->vec.w, this->vec.z, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::zwwx() const { return Vec4(this->vec.z, this->vec.w, this->vec.w, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::zwwy() const { return Vec4(this->vec.z, this->vec.w, this->vec.w, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::zwwz() const { return Vec4(this->vec.z, this->vec.w, this->vec.w, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::zwww() const { return Vec4(this->vec.z, this->vec.w, this->vec.w, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::wxxx() const { return Vec4(this->vec.w, this->vec.x, this->vec.x, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::wxxy() const { return Vec4(this->vec.w, this->vec.x, this->vec.x, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::wxxz() const { return Vec4(this->vec.w, this->vec.x, this->vec.x, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::wxxw() const { return Vec4(this->vec.w, this->vec.x, this->vec.x, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::wxyx() const { return Vec4(this->vec.w, this->vec.x, this->vec.y, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::wxyy() const { return Vec4(this->vec.w, this->vec.x, this->vec.y, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::wxyz() const { return Vec4(this->vec.w, this->vec.x, this->vec.y, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::wxyw() const { return Vec4(this->vec.w, this->vec.x, this->vec.y, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::wxzx() const { return Vec4(this->vec.w, this->vec.x, this->vec.z, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::wxzy() const { return Vec4(this->vec.w, this->vec.x, this->vec.z, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::wxzz() const { return Vec4(this->vec.w, this->vec.x, this->vec.z, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::wxzw() const { return Vec4(this->vec.w, this->vec.x, this->vec.z, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::wxwx() const { return Vec4(this->vec.w, this->vec.x, this->vec.w, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::wxwy() const { return Vec4(this->vec.w, this->vec.x, this->vec.w, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::wxwz() const { return Vec4(this->vec.w, this->vec.x, this->vec.w, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::wxww() const { return Vec4(this->vec.w, this->vec.x, this->vec.w, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::wyxx() const { return Vec4(this->vec.w, this->vec.y, this->vec.x, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::wyxy() const { return Vec4(this->vec.w, this->vec.y, this->vec.x, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::wyxz() const { return Vec4(this->vec.w, this->vec.y, this->vec.x, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::wyxw() const { return Vec4(this->vec.w, this->vec.y, this->vec.x, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::wyyx() const { return Vec4(this->vec.w, this->vec.y, this->vec.y, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::wyyy() const { return Vec4(this->vec.w, this->vec.y, this->vec.y, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::wyyz() const { return Vec4(this->vec.w, this->vec.y, this->vec.y, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::wyyw() const { return Vec4(this->vec.w, this->vec.y, this->vec.y, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::wyzx() const { return Vec4(this->vec.w, this->vec.y, this->vec.z, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::wyzy() const { return Vec4(this->vec.w, this->vec.y, this->vec.z, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::wyzz() const { return Vec4(this->vec.w, this->vec.y, this->vec.z, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::wyzw() const { return Vec4(this->vec.w, this->vec.y, this->vec.z, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::wywx() const { return Vec4(this->vec.w, this->vec.y, this->vec.w, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::wywy() const { return Vec4(this->vec.w, this->vec.y, this->vec.w, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::wywz() const { return Vec4(this->vec.w, this->vec.y, this->vec.w, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::wyww() const { return Vec4(this->vec.w, this->vec.y, this->vec.w, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::wzxx() const { return Vec4(this->vec.w, this->vec.z, this->vec.x, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::wzxy() const { return Vec4(this->vec.w, this->vec.z, this->vec.x, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::wzxz() const { return Vec4(this->vec.w, this->vec.z, this->vec.x, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::wzxw() const { return Vec4(this->vec.w, this->vec.z, this->vec.x, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::wzyx() const { return Vec4(this->vec.w, this->vec.z, this->vec.y, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::wzyy() const { return Vec4(this->vec.w, this->vec.z, this->vec.y, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::wzyz() const { return Vec4(this->vec.w, this->vec.z, this->vec.y, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::wzyw() const { return Vec4(this->vec.w, this->vec.z, this->vec.y, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::wzzx() const { return Vec4(this->vec.w, this->vec.z, this->vec.z, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::wzzy() const { return Vec4(this->vec.w, this->vec.z, this->vec.z, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::wzzz() const { return Vec4(this->vec.w, this->vec.z, this->vec.z, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::wzzw() const { return Vec4(this->vec.w, this->vec.z, this->vec.z, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::wzwx() const { return Vec4(this->vec.w, this->vec.z, this->vec.w, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::wzwy() const { return Vec4(this->vec.w, this->vec.z, this->vec.w, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::wzwz() const { return Vec4(this->vec.w, this->vec.z, this->vec.w, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::wzww() const { return Vec4(this->vec.w, this->vec.z, this->vec.w, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::wwxx() const { return Vec4(this->vec.w, this->vec.w, this->vec.x, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::wwxy() const { return Vec4(this->vec.w, this->vec.w, this->vec.x, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::wwxz() const { return Vec4(this->vec.w, this->vec.w, this->vec.x, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::wwxw() const { return Vec4(this->vec.w, this->vec.w, this->vec.x, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::wwyx() const { return Vec4(this->vec.w, this->vec.w, this->vec.y, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::wwyy() const { return Vec4(this->vec.w, this->vec.w, this->vec.y, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::wwyz() const { return Vec4(this->vec.w, this->vec.w, this->vec.y, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::wwyw() const { return Vec4(this->vec.w, this->vec.w, this->vec.y, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::wwzx() const { return Vec4(this->vec.w, this->vec.w, this->vec.z, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::wwzy() const { return Vec4(this->vec.w, this->vec.w, this->vec.z, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::wwzz() const { return Vec4(this->vec.w, this->vec.w, this->vec.z, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::wwzw() const { return Vec4(this->vec.w, this->vec.w, this->vec.z, this->vec.w); }
onyx::math::Vec4 onyx::math::Vec4::wwwx() const { return Vec4(this->vec.w, this->vec.w, this->vec.w, this->vec.x); }
onyx::math::Vec4 onyx::math::Vec4::wwwy() const { return Vec4(this->vec.w, this->vec.w, this->vec.w, this->vec.y); }
onyx::math::Vec4 onyx::math::Vec4::wwwz() const { return Vec4(this->vec.w, this->vec.w, this->vec.w, this->vec.z); }
onyx::math::Vec4 onyx::math::Vec4::wwww() const { return Vec4(this->vec.w, this->vec.w, this->vec.w, this->vec.w); }





onyx::math::DVec2 onyx::math::DVec2::xx() const { return DVec2(this->vec.x, this->vec.x); }
onyx::math::DVec2 onyx::math::DVec2::xy() const { return DVec2(this->vec.x, this->vec.x); }
onyx::math::DVec2 onyx::math::DVec2::yx() const { return DVec2(this->vec.x, this->vec.x); }
onyx::math::DVec2 onyx::math::DVec2::yy() const { return DVec2(this->vec.x, this->vec.x); }


onyx::math::DVec2 onyx::math::DVec3::xx() const { return DVec2(this->vec.x, this->vec.x); }
onyx::math::DVec2 onyx::math::DVec3::xy() const { return DVec2(this->vec.x, this->vec.y); }
onyx::math::DVec2 onyx::math::DVec3::xz() const { return DVec2(this->vec.x, this->vec.z); }
onyx::math::DVec2 onyx::math::DVec3::yx() const { return DVec2(this->vec.y, this->vec.x); }
onyx::math::DVec2 onyx::math::DVec3::yy() const { return DVec2(this->vec.y, this->vec.y); }
onyx::math::DVec2 onyx::math::DVec3::yz() const { return DVec2(this->vec.y, this->vec.z); }
onyx::math::DVec2 onyx::math::DVec3::zx() const { return DVec2(this->vec.z, this->vec.x); }
onyx::math::DVec2 onyx::math::DVec3::zy() const { return DVec2(this->vec.z, this->vec.y); }
onyx::math::DVec2 onyx::math::DVec3::zz() const { return DVec2(this->vec.z, this->vec.z); }

onyx::math::DVec3 onyx::math::DVec3::xxx() const { return DVec3(this->vec.x, this->vec.x, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec3::xxy() const { return DVec3(this->vec.x, this->vec.x, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec3::xxz() const { return DVec3(this->vec.x, this->vec.x, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec3::xyx() const { return DVec3(this->vec.x, this->vec.y, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec3::xyy() const { return DVec3(this->vec.x, this->vec.y, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec3::xyz() const { return DVec3(this->vec.x, this->vec.y, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec3::xzx() const { return DVec3(this->vec.x, this->vec.z, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec3::xzy() const { return DVec3(this->vec.x, this->vec.z, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec3::xzz() const { return DVec3(this->vec.x, this->vec.z, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec3::yxx() const { return DVec3(this->vec.y, this->vec.x, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec3::yxy() const { return DVec3(this->vec.y, this->vec.x, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec3::yxz() const { return DVec3(this->vec.y, this->vec.x, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec3::yyx() const { return DVec3(this->vec.y, this->vec.y, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec3::yyy() const { return DVec3(this->vec.y, this->vec.y, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec3::yyz() const { return DVec3(this->vec.y, this->vec.y, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec3::yzx() const { return DVec3(this->vec.y, this->vec.z, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec3::yzy() const { return DVec3(this->vec.y, this->vec.z, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec3::yzz() const { return DVec3(this->vec.y, this->vec.z, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec3::zxx() const { return DVec3(this->vec.z, this->vec.x, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec3::zxy() const { return DVec3(this->vec.z, this->vec.x, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec3::zxz() const { return DVec3(this->vec.z, this->vec.x, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec3::zyx() const { return DVec3(this->vec.z, this->vec.y, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec3::zyy() const { return DVec3(this->vec.z, this->vec.y, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec3::zyz() const { return DVec3(this->vec.z, this->vec.y, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec3::zzx() const { return DVec3(this->vec.z, this->vec.z, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec3::zzy() const { return DVec3(this->vec.z, this->vec.z, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec3::zzz() const { return DVec3(this->vec.z, this->vec.z, this->vec.z); }


onyx::math::DVec2 onyx::math::DVec4::xx() const { return DVec2(this->vec.x, this->vec.x); }
onyx::math::DVec2 onyx::math::DVec4::xy() const { return DVec2(this->vec.x, this->vec.y); }
onyx::math::DVec2 onyx::math::DVec4::xz() const { return DVec2(this->vec.x, this->vec.z); }
onyx::math::DVec2 onyx::math::DVec4::xw() const { return DVec2(this->vec.x, this->vec.w); }
onyx::math::DVec2 onyx::math::DVec4::yx() const { return DVec2(this->vec.y, this->vec.x); }
onyx::math::DVec2 onyx::math::DVec4::yy() const { return DVec2(this->vec.y, this->vec.y); }
onyx::math::DVec2 onyx::math::DVec4::yz() const { return DVec2(this->vec.y, this->vec.z); }
onyx::math::DVec2 onyx::math::DVec4::yw() const { return DVec2(this->vec.y, this->vec.w); }
onyx::math::DVec2 onyx::math::DVec4::zx() const { return DVec2(this->vec.z, this->vec.x); }
onyx::math::DVec2 onyx::math::DVec4::zy() const { return DVec2(this->vec.z, this->vec.y); }
onyx::math::DVec2 onyx::math::DVec4::zz() const { return DVec2(this->vec.z, this->vec.z); }
onyx::math::DVec2 onyx::math::DVec4::zw() const { return DVec2(this->vec.z, this->vec.w); }
onyx::math::DVec2 onyx::math::DVec4::wx() const { return DVec2(this->vec.w, this->vec.x); }
onyx::math::DVec2 onyx::math::DVec4::wy() const { return DVec2(this->vec.w, this->vec.y); }
onyx::math::DVec2 onyx::math::DVec4::wz() const { return DVec2(this->vec.w, this->vec.z); }
onyx::math::DVec2 onyx::math::DVec4::ww() const { return DVec2(this->vec.w, this->vec.w); }

onyx::math::DVec3 onyx::math::DVec4::xxx() const { return DVec3(this->vec.x, this->vec.x, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec4::xxy() const { return DVec3(this->vec.x, this->vec.x, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec4::xxz() const { return DVec3(this->vec.x, this->vec.x, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec4::xxw() const { return DVec3(this->vec.x, this->vec.x, this->vec.w); }
onyx::math::DVec3 onyx::math::DVec4::xyx() const { return DVec3(this->vec.x, this->vec.y, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec4::xyy() const { return DVec3(this->vec.x, this->vec.y, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec4::xyz() const { return DVec3(this->vec.x, this->vec.y, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec4::xyw() const { return DVec3(this->vec.x, this->vec.y, this->vec.w); }
onyx::math::DVec3 onyx::math::DVec4::xzx() const { return DVec3(this->vec.x, this->vec.z, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec4::xzy() const { return DVec3(this->vec.x, this->vec.z, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec4::xzz() const { return DVec3(this->vec.x, this->vec.z, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec4::xzw() const { return DVec3(this->vec.x, this->vec.z, this->vec.w); }
onyx::math::DVec3 onyx::math::DVec4::xwx() const { return DVec3(this->vec.x, this->vec.w, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec4::xwy() const { return DVec3(this->vec.x, this->vec.w, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec4::xwz() const { return DVec3(this->vec.x, this->vec.w, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec4::xww() const { return DVec3(this->vec.x, this->vec.w, this->vec.w); }
onyx::math::DVec3 onyx::math::DVec4::yxx() const { return DVec3(this->vec.y, this->vec.x, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec4::yxy() const { return DVec3(this->vec.y, this->vec.x, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec4::yxz() const { return DVec3(this->vec.y, this->vec.x, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec4::yxw() const { return DVec3(this->vec.y, this->vec.x, this->vec.w); }
onyx::math::DVec3 onyx::math::DVec4::yyx() const { return DVec3(this->vec.y, this->vec.y, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec4::yyy() const { return DVec3(this->vec.y, this->vec.y, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec4::yyz() const { return DVec3(this->vec.y, this->vec.y, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec4::yyw() const { return DVec3(this->vec.y, this->vec.y, this->vec.w); }
onyx::math::DVec3 onyx::math::DVec4::yzx() const { return DVec3(this->vec.y, this->vec.z, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec4::yzy() const { return DVec3(this->vec.y, this->vec.z, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec4::yzz() const { return DVec3(this->vec.y, this->vec.z, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec4::yzw() const { return DVec3(this->vec.y, this->vec.z, this->vec.w); }
onyx::math::DVec3 onyx::math::DVec4::ywx() const { return DVec3(this->vec.y, this->vec.w, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec4::ywy() const { return DVec3(this->vec.y, this->vec.w, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec4::ywz() const { return DVec3(this->vec.y, this->vec.w, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec4::yww() const { return DVec3(this->vec.y, this->vec.w, this->vec.w); }
onyx::math::DVec3 onyx::math::DVec4::zxx() const { return DVec3(this->vec.z, this->vec.x, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec4::zxy() const { return DVec3(this->vec.z, this->vec.x, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec4::zxz() const { return DVec3(this->vec.z, this->vec.x, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec4::zxw() const { return DVec3(this->vec.z, this->vec.x, this->vec.w); }
onyx::math::DVec3 onyx::math::DVec4::zyx() const { return DVec3(this->vec.z, this->vec.y, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec4::zyy() const { return DVec3(this->vec.z, this->vec.y, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec4::zyz() const { return DVec3(this->vec.z, this->vec.y, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec4::zyw() const { return DVec3(this->vec.z, this->vec.y, this->vec.w); }
onyx::math::DVec3 onyx::math::DVec4::zzx() const { return DVec3(this->vec.z, this->vec.z, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec4::zzy() const { return DVec3(this->vec.z, this->vec.z, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec4::zzz() const { return DVec3(this->vec.z, this->vec.z, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec4::zzw() const { return DVec3(this->vec.z, this->vec.z, this->vec.w); }
onyx::math::DVec3 onyx::math::DVec4::zwx() const { return DVec3(this->vec.z, this->vec.w, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec4::zwy() const { return DVec3(this->vec.z, this->vec.w, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec4::zwz() const { return DVec3(this->vec.z, this->vec.w, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec4::zww() const { return DVec3(this->vec.z, this->vec.w, this->vec.w); }
onyx::math::DVec3 onyx::math::DVec4::wxx() const { return DVec3(this->vec.w, this->vec.x, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec4::wxy() const { return DVec3(this->vec.w, this->vec.x, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec4::wxz() const { return DVec3(this->vec.w, this->vec.x, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec4::wxw() const { return DVec3(this->vec.w, this->vec.x, this->vec.w); }
onyx::math::DVec3 onyx::math::DVec4::wyx() const { return DVec3(this->vec.w, this->vec.y, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec4::wyy() const { return DVec3(this->vec.w, this->vec.y, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec4::wyz() const { return DVec3(this->vec.w, this->vec.y, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec4::wyw() const { return DVec3(this->vec.w, this->vec.y, this->vec.w); }
onyx::math::DVec3 onyx::math::DVec4::wzx() const { return DVec3(this->vec.w, this->vec.z, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec4::wzy() const { return DVec3(this->vec.w, this->vec.z, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec4::wzz() const { return DVec3(this->vec.w, this->vec.z, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec4::wzw() const { return DVec3(this->vec.w, this->vec.z, this->vec.w); }
onyx::math::DVec3 onyx::math::DVec4::wwx() const { return DVec3(this->vec.w, this->vec.w, this->vec.x); }
onyx::math::DVec3 onyx::math::DVec4::wwy() const { return DVec3(this->vec.w, this->vec.w, this->vec.y); }
onyx::math::DVec3 onyx::math::DVec4::wwz() const { return DVec3(this->vec.w, this->vec.w, this->vec.z); }
onyx::math::DVec3 onyx::math::DVec4::www() const { return DVec3(this->vec.w, this->vec.w, this->vec.w); }

onyx::math::DVec4 onyx::math::DVec4::xxxx() const { return DVec4(this->vec.x, this->vec.x, this->vec.x, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::xxxy() const { return DVec4(this->vec.x, this->vec.x, this->vec.x, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::xxxz() const { return DVec4(this->vec.x, this->vec.x, this->vec.x, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::xxxw() const { return DVec4(this->vec.x, this->vec.x, this->vec.x, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::xxyx() const { return DVec4(this->vec.x, this->vec.x, this->vec.y, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::xxyy() const { return DVec4(this->vec.x, this->vec.x, this->vec.y, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::xxyz() const { return DVec4(this->vec.x, this->vec.x, this->vec.y, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::xxyw() const { return DVec4(this->vec.x, this->vec.x, this->vec.y, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::xxzx() const { return DVec4(this->vec.x, this->vec.x, this->vec.z, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::xxzy() const { return DVec4(this->vec.x, this->vec.x, this->vec.z, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::xxzz() const { return DVec4(this->vec.x, this->vec.x, this->vec.z, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::xxzw() const { return DVec4(this->vec.x, this->vec.x, this->vec.z, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::xxwx() const { return DVec4(this->vec.x, this->vec.x, this->vec.w, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::xxwy() const { return DVec4(this->vec.x, this->vec.x, this->vec.w, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::xxwz() const { return DVec4(this->vec.x, this->vec.x, this->vec.w, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::xxww() const { return DVec4(this->vec.x, this->vec.x, this->vec.w, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::xyxx() const { return DVec4(this->vec.x, this->vec.y, this->vec.x, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::xyxy() const { return DVec4(this->vec.x, this->vec.y, this->vec.x, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::xyxz() const { return DVec4(this->vec.x, this->vec.y, this->vec.x, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::xyxw() const { return DVec4(this->vec.x, this->vec.y, this->vec.x, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::xyyx() const { return DVec4(this->vec.x, this->vec.y, this->vec.y, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::xyyy() const { return DVec4(this->vec.x, this->vec.y, this->vec.y, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::xyyz() const { return DVec4(this->vec.x, this->vec.y, this->vec.y, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::xyyw() const { return DVec4(this->vec.x, this->vec.y, this->vec.y, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::xyzx() const { return DVec4(this->vec.x, this->vec.y, this->vec.z, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::xyzy() const { return DVec4(this->vec.x, this->vec.y, this->vec.z, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::xyzz() const { return DVec4(this->vec.x, this->vec.y, this->vec.z, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::xyzw() const { return DVec4(this->vec.x, this->vec.y, this->vec.z, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::xywx() const { return DVec4(this->vec.x, this->vec.y, this->vec.w, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::xywy() const { return DVec4(this->vec.x, this->vec.y, this->vec.w, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::xywz() const { return DVec4(this->vec.x, this->vec.y, this->vec.w, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::xyww() const { return DVec4(this->vec.x, this->vec.y, this->vec.w, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::xzxx() const { return DVec4(this->vec.x, this->vec.z, this->vec.x, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::xzxy() const { return DVec4(this->vec.x, this->vec.z, this->vec.x, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::xzxz() const { return DVec4(this->vec.x, this->vec.z, this->vec.x, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::xzxw() const { return DVec4(this->vec.x, this->vec.z, this->vec.x, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::xzyx() const { return DVec4(this->vec.x, this->vec.z, this->vec.y, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::xzyy() const { return DVec4(this->vec.x, this->vec.z, this->vec.y, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::xzyz() const { return DVec4(this->vec.x, this->vec.z, this->vec.y, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::xzyw() const { return DVec4(this->vec.x, this->vec.z, this->vec.y, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::xzzx() const { return DVec4(this->vec.x, this->vec.z, this->vec.z, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::xzzy() const { return DVec4(this->vec.x, this->vec.z, this->vec.z, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::xzzz() const { return DVec4(this->vec.x, this->vec.z, this->vec.z, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::xzzw() const { return DVec4(this->vec.x, this->vec.z, this->vec.z, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::xzwx() const { return DVec4(this->vec.x, this->vec.z, this->vec.w, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::xzwy() const { return DVec4(this->vec.x, this->vec.z, this->vec.w, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::xzwz() const { return DVec4(this->vec.x, this->vec.z, this->vec.w, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::xzww() const { return DVec4(this->vec.x, this->vec.z, this->vec.w, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::xwxx() const { return DVec4(this->vec.x, this->vec.w, this->vec.x, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::xwxy() const { return DVec4(this->vec.x, this->vec.w, this->vec.x, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::xwxz() const { return DVec4(this->vec.x, this->vec.w, this->vec.x, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::xwxw() const { return DVec4(this->vec.x, this->vec.w, this->vec.x, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::xwyx() const { return DVec4(this->vec.x, this->vec.w, this->vec.y, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::xwyy() const { return DVec4(this->vec.x, this->vec.w, this->vec.y, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::xwyz() const { return DVec4(this->vec.x, this->vec.w, this->vec.y, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::xwyw() const { return DVec4(this->vec.x, this->vec.w, this->vec.y, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::xwzx() const { return DVec4(this->vec.x, this->vec.w, this->vec.z, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::xwzy() const { return DVec4(this->vec.x, this->vec.w, this->vec.z, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::xwzz() const { return DVec4(this->vec.x, this->vec.w, this->vec.z, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::xwzw() const { return DVec4(this->vec.x, this->vec.w, this->vec.z, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::xwwx() const { return DVec4(this->vec.x, this->vec.w, this->vec.w, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::xwwy() const { return DVec4(this->vec.x, this->vec.w, this->vec.w, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::xwwz() const { return DVec4(this->vec.x, this->vec.w, this->vec.w, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::xwww() const { return DVec4(this->vec.x, this->vec.w, this->vec.w, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::yxxx() const { return DVec4(this->vec.y, this->vec.x, this->vec.x, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::yxxy() const { return DVec4(this->vec.y, this->vec.x, this->vec.x, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::yxxz() const { return DVec4(this->vec.y, this->vec.x, this->vec.x, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::yxxw() const { return DVec4(this->vec.y, this->vec.x, this->vec.x, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::yxyx() const { return DVec4(this->vec.y, this->vec.x, this->vec.y, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::yxyy() const { return DVec4(this->vec.y, this->vec.x, this->vec.y, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::yxyz() const { return DVec4(this->vec.y, this->vec.x, this->vec.y, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::yxyw() const { return DVec4(this->vec.y, this->vec.x, this->vec.y, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::yxzx() const { return DVec4(this->vec.y, this->vec.x, this->vec.z, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::yxzy() const { return DVec4(this->vec.y, this->vec.x, this->vec.z, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::yxzz() const { return DVec4(this->vec.y, this->vec.x, this->vec.z, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::yxzw() const { return DVec4(this->vec.y, this->vec.x, this->vec.z, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::yxwx() const { return DVec4(this->vec.y, this->vec.x, this->vec.w, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::yxwy() const { return DVec4(this->vec.y, this->vec.x, this->vec.w, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::yxwz() const { return DVec4(this->vec.y, this->vec.x, this->vec.w, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::yxww() const { return DVec4(this->vec.y, this->vec.x, this->vec.w, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::yyxx() const { return DVec4(this->vec.y, this->vec.y, this->vec.x, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::yyxy() const { return DVec4(this->vec.y, this->vec.y, this->vec.x, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::yyxz() const { return DVec4(this->vec.y, this->vec.y, this->vec.x, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::yyxw() const { return DVec4(this->vec.y, this->vec.y, this->vec.x, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::yyyx() const { return DVec4(this->vec.y, this->vec.y, this->vec.y, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::yyyy() const { return DVec4(this->vec.y, this->vec.y, this->vec.y, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::yyyz() const { return DVec4(this->vec.y, this->vec.y, this->vec.y, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::yyyw() const { return DVec4(this->vec.y, this->vec.y, this->vec.y, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::yyzx() const { return DVec4(this->vec.y, this->vec.y, this->vec.z, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::yyzy() const { return DVec4(this->vec.y, this->vec.y, this->vec.z, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::yyzz() const { return DVec4(this->vec.y, this->vec.y, this->vec.z, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::yyzw() const { return DVec4(this->vec.y, this->vec.y, this->vec.z, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::yywx() const { return DVec4(this->vec.y, this->vec.y, this->vec.w, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::yywy() const { return DVec4(this->vec.y, this->vec.y, this->vec.w, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::yywz() const { return DVec4(this->vec.y, this->vec.y, this->vec.w, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::yyww() const { return DVec4(this->vec.y, this->vec.y, this->vec.w, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::yzxx() const { return DVec4(this->vec.y, this->vec.z, this->vec.x, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::yzxy() const { return DVec4(this->vec.y, this->vec.z, this->vec.x, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::yzxz() const { return DVec4(this->vec.y, this->vec.z, this->vec.x, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::yzxw() const { return DVec4(this->vec.y, this->vec.z, this->vec.x, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::yzyx() const { return DVec4(this->vec.y, this->vec.z, this->vec.y, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::yzyy() const { return DVec4(this->vec.y, this->vec.z, this->vec.y, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::yzyz() const { return DVec4(this->vec.y, this->vec.z, this->vec.y, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::yzyw() const { return DVec4(this->vec.y, this->vec.z, this->vec.y, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::yzzx() const { return DVec4(this->vec.y, this->vec.z, this->vec.z, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::yzzy() const { return DVec4(this->vec.y, this->vec.z, this->vec.z, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::yzzz() const { return DVec4(this->vec.y, this->vec.z, this->vec.z, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::yzzw() const { return DVec4(this->vec.y, this->vec.z, this->vec.z, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::yzwx() const { return DVec4(this->vec.y, this->vec.z, this->vec.w, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::yzwy() const { return DVec4(this->vec.y, this->vec.z, this->vec.w, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::yzwz() const { return DVec4(this->vec.y, this->vec.z, this->vec.w, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::yzww() const { return DVec4(this->vec.y, this->vec.z, this->vec.w, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::ywxx() const { return DVec4(this->vec.y, this->vec.w, this->vec.x, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::ywxy() const { return DVec4(this->vec.y, this->vec.w, this->vec.x, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::ywxz() const { return DVec4(this->vec.y, this->vec.w, this->vec.x, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::ywxw() const { return DVec4(this->vec.y, this->vec.w, this->vec.x, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::ywyx() const { return DVec4(this->vec.y, this->vec.w, this->vec.y, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::ywyy() const { return DVec4(this->vec.y, this->vec.w, this->vec.y, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::ywyz() const { return DVec4(this->vec.y, this->vec.w, this->vec.y, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::ywyw() const { return DVec4(this->vec.y, this->vec.w, this->vec.y, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::ywzx() const { return DVec4(this->vec.y, this->vec.w, this->vec.z, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::ywzy() const { return DVec4(this->vec.y, this->vec.w, this->vec.z, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::ywzz() const { return DVec4(this->vec.y, this->vec.w, this->vec.z, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::ywzw() const { return DVec4(this->vec.y, this->vec.w, this->vec.z, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::ywwx() const { return DVec4(this->vec.y, this->vec.w, this->vec.w, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::ywwy() const { return DVec4(this->vec.y, this->vec.w, this->vec.w, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::ywwz() const { return DVec4(this->vec.y, this->vec.w, this->vec.w, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::ywww() const { return DVec4(this->vec.y, this->vec.w, this->vec.w, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::zxxx() const { return DVec4(this->vec.z, this->vec.x, this->vec.x, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::zxxy() const { return DVec4(this->vec.z, this->vec.x, this->vec.x, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::zxxz() const { return DVec4(this->vec.z, this->vec.x, this->vec.x, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::zxxw() const { return DVec4(this->vec.z, this->vec.x, this->vec.x, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::zxyx() const { return DVec4(this->vec.z, this->vec.x, this->vec.y, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::zxyy() const { return DVec4(this->vec.z, this->vec.x, this->vec.y, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::zxyz() const { return DVec4(this->vec.z, this->vec.x, this->vec.y, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::zxyw() const { return DVec4(this->vec.z, this->vec.x, this->vec.y, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::zxzx() const { return DVec4(this->vec.z, this->vec.x, this->vec.z, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::zxzy() const { return DVec4(this->vec.z, this->vec.x, this->vec.z, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::zxzz() const { return DVec4(this->vec.z, this->vec.x, this->vec.z, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::zxzw() const { return DVec4(this->vec.z, this->vec.x, this->vec.z, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::zxwx() const { return DVec4(this->vec.z, this->vec.x, this->vec.w, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::zxwy() const { return DVec4(this->vec.z, this->vec.x, this->vec.w, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::zxwz() const { return DVec4(this->vec.z, this->vec.x, this->vec.w, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::zxww() const { return DVec4(this->vec.z, this->vec.x, this->vec.w, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::zyxx() const { return DVec4(this->vec.z, this->vec.y, this->vec.x, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::zyxy() const { return DVec4(this->vec.z, this->vec.y, this->vec.x, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::zyxz() const { return DVec4(this->vec.z, this->vec.y, this->vec.x, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::zyxw() const { return DVec4(this->vec.z, this->vec.y, this->vec.x, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::zyyx() const { return DVec4(this->vec.z, this->vec.y, this->vec.y, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::zyyy() const { return DVec4(this->vec.z, this->vec.y, this->vec.y, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::zyyz() const { return DVec4(this->vec.z, this->vec.y, this->vec.y, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::zyyw() const { return DVec4(this->vec.z, this->vec.y, this->vec.y, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::zyzx() const { return DVec4(this->vec.z, this->vec.y, this->vec.z, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::zyzy() const { return DVec4(this->vec.z, this->vec.y, this->vec.z, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::zyzz() const { return DVec4(this->vec.z, this->vec.y, this->vec.z, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::zyzw() const { return DVec4(this->vec.z, this->vec.y, this->vec.z, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::zywx() const { return DVec4(this->vec.z, this->vec.y, this->vec.w, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::zywy() const { return DVec4(this->vec.z, this->vec.y, this->vec.w, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::zywz() const { return DVec4(this->vec.z, this->vec.y, this->vec.w, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::zyww() const { return DVec4(this->vec.z, this->vec.y, this->vec.w, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::zzxx() const { return DVec4(this->vec.z, this->vec.z, this->vec.x, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::zzxy() const { return DVec4(this->vec.z, this->vec.z, this->vec.x, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::zzxz() const { return DVec4(this->vec.z, this->vec.z, this->vec.x, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::zzxw() const { return DVec4(this->vec.z, this->vec.z, this->vec.x, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::zzyx() const { return DVec4(this->vec.z, this->vec.z, this->vec.y, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::zzyy() const { return DVec4(this->vec.z, this->vec.z, this->vec.y, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::zzyz() const { return DVec4(this->vec.z, this->vec.z, this->vec.y, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::zzyw() const { return DVec4(this->vec.z, this->vec.z, this->vec.y, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::zzzx() const { return DVec4(this->vec.z, this->vec.z, this->vec.z, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::zzzy() const { return DVec4(this->vec.z, this->vec.z, this->vec.z, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::zzzz() const { return DVec4(this->vec.z, this->vec.z, this->vec.z, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::zzzw() const { return DVec4(this->vec.z, this->vec.z, this->vec.z, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::zzwx() const { return DVec4(this->vec.z, this->vec.z, this->vec.w, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::zzwy() const { return DVec4(this->vec.z, this->vec.z, this->vec.w, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::zzwz() const { return DVec4(this->vec.z, this->vec.z, this->vec.w, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::zzww() const { return DVec4(this->vec.z, this->vec.z, this->vec.w, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::zwxx() const { return DVec4(this->vec.z, this->vec.w, this->vec.x, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::zwxy() const { return DVec4(this->vec.z, this->vec.w, this->vec.x, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::zwxz() const { return DVec4(this->vec.z, this->vec.w, this->vec.x, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::zwxw() const { return DVec4(this->vec.z, this->vec.w, this->vec.x, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::zwyx() const { return DVec4(this->vec.z, this->vec.w, this->vec.y, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::zwyy() const { return DVec4(this->vec.z, this->vec.w, this->vec.y, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::zwyz() const { return DVec4(this->vec.z, this->vec.w, this->vec.y, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::zwyw() const { return DVec4(this->vec.z, this->vec.w, this->vec.y, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::zwzx() const { return DVec4(this->vec.z, this->vec.w, this->vec.z, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::zwzy() const { return DVec4(this->vec.z, this->vec.w, this->vec.z, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::zwzz() const { return DVec4(this->vec.z, this->vec.w, this->vec.z, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::zwzw() const { return DVec4(this->vec.z, this->vec.w, this->vec.z, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::zwwx() const { return DVec4(this->vec.z, this->vec.w, this->vec.w, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::zwwy() const { return DVec4(this->vec.z, this->vec.w, this->vec.w, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::zwwz() const { return DVec4(this->vec.z, this->vec.w, this->vec.w, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::zwww() const { return DVec4(this->vec.z, this->vec.w, this->vec.w, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::wxxx() const { return DVec4(this->vec.w, this->vec.x, this->vec.x, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::wxxy() const { return DVec4(this->vec.w, this->vec.x, this->vec.x, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::wxxz() const { return DVec4(this->vec.w, this->vec.x, this->vec.x, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::wxxw() const { return DVec4(this->vec.w, this->vec.x, this->vec.x, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::wxyx() const { return DVec4(this->vec.w, this->vec.x, this->vec.y, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::wxyy() const { return DVec4(this->vec.w, this->vec.x, this->vec.y, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::wxyz() const { return DVec4(this->vec.w, this->vec.x, this->vec.y, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::wxyw() const { return DVec4(this->vec.w, this->vec.x, this->vec.y, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::wxzx() const { return DVec4(this->vec.w, this->vec.x, this->vec.z, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::wxzy() const { return DVec4(this->vec.w, this->vec.x, this->vec.z, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::wxzz() const { return DVec4(this->vec.w, this->vec.x, this->vec.z, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::wxzw() const { return DVec4(this->vec.w, this->vec.x, this->vec.z, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::wxwx() const { return DVec4(this->vec.w, this->vec.x, this->vec.w, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::wxwy() const { return DVec4(this->vec.w, this->vec.x, this->vec.w, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::wxwz() const { return DVec4(this->vec.w, this->vec.x, this->vec.w, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::wxww() const { return DVec4(this->vec.w, this->vec.x, this->vec.w, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::wyxx() const { return DVec4(this->vec.w, this->vec.y, this->vec.x, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::wyxy() const { return DVec4(this->vec.w, this->vec.y, this->vec.x, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::wyxz() const { return DVec4(this->vec.w, this->vec.y, this->vec.x, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::wyxw() const { return DVec4(this->vec.w, this->vec.y, this->vec.x, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::wyyx() const { return DVec4(this->vec.w, this->vec.y, this->vec.y, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::wyyy() const { return DVec4(this->vec.w, this->vec.y, this->vec.y, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::wyyz() const { return DVec4(this->vec.w, this->vec.y, this->vec.y, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::wyyw() const { return DVec4(this->vec.w, this->vec.y, this->vec.y, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::wyzx() const { return DVec4(this->vec.w, this->vec.y, this->vec.z, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::wyzy() const { return DVec4(this->vec.w, this->vec.y, this->vec.z, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::wyzz() const { return DVec4(this->vec.w, this->vec.y, this->vec.z, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::wyzw() const { return DVec4(this->vec.w, this->vec.y, this->vec.z, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::wywx() const { return DVec4(this->vec.w, this->vec.y, this->vec.w, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::wywy() const { return DVec4(this->vec.w, this->vec.y, this->vec.w, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::wywz() const { return DVec4(this->vec.w, this->vec.y, this->vec.w, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::wyww() const { return DVec4(this->vec.w, this->vec.y, this->vec.w, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::wzxx() const { return DVec4(this->vec.w, this->vec.z, this->vec.x, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::wzxy() const { return DVec4(this->vec.w, this->vec.z, this->vec.x, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::wzxz() const { return DVec4(this->vec.w, this->vec.z, this->vec.x, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::wzxw() const { return DVec4(this->vec.w, this->vec.z, this->vec.x, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::wzyx() const { return DVec4(this->vec.w, this->vec.z, this->vec.y, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::wzyy() const { return DVec4(this->vec.w, this->vec.z, this->vec.y, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::wzyz() const { return DVec4(this->vec.w, this->vec.z, this->vec.y, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::wzyw() const { return DVec4(this->vec.w, this->vec.z, this->vec.y, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::wzzx() const { return DVec4(this->vec.w, this->vec.z, this->vec.z, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::wzzy() const { return DVec4(this->vec.w, this->vec.z, this->vec.z, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::wzzz() const { return DVec4(this->vec.w, this->vec.z, this->vec.z, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::wzzw() const { return DVec4(this->vec.w, this->vec.z, this->vec.z, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::wzwx() const { return DVec4(this->vec.w, this->vec.z, this->vec.w, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::wzwy() const { return DVec4(this->vec.w, this->vec.z, this->vec.w, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::wzwz() const { return DVec4(this->vec.w, this->vec.z, this->vec.w, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::wzww() const { return DVec4(this->vec.w, this->vec.z, this->vec.w, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::wwxx() const { return DVec4(this->vec.w, this->vec.w, this->vec.x, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::wwxy() const { return DVec4(this->vec.w, this->vec.w, this->vec.x, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::wwxz() const { return DVec4(this->vec.w, this->vec.w, this->vec.x, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::wwxw() const { return DVec4(this->vec.w, this->vec.w, this->vec.x, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::wwyx() const { return DVec4(this->vec.w, this->vec.w, this->vec.y, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::wwyy() const { return DVec4(this->vec.w, this->vec.w, this->vec.y, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::wwyz() const { return DVec4(this->vec.w, this->vec.w, this->vec.y, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::wwyw() const { return DVec4(this->vec.w, this->vec.w, this->vec.y, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::wwzx() const { return DVec4(this->vec.w, this->vec.w, this->vec.z, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::wwzy() const { return DVec4(this->vec.w, this->vec.w, this->vec.z, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::wwzz() const { return DVec4(this->vec.w, this->vec.w, this->vec.z, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::wwzw() const { return DVec4(this->vec.w, this->vec.w, this->vec.z, this->vec.w); }
onyx::math::DVec4 onyx::math::DVec4::wwwx() const { return DVec4(this->vec.w, this->vec.w, this->vec.w, this->vec.x); }
onyx::math::DVec4 onyx::math::DVec4::wwwy() const { return DVec4(this->vec.w, this->vec.w, this->vec.w, this->vec.y); }
onyx::math::DVec4 onyx::math::DVec4::wwwz() const { return DVec4(this->vec.w, this->vec.w, this->vec.w, this->vec.z); }
onyx::math::DVec4 onyx::math::DVec4::wwww() const { return DVec4(this->vec.w, this->vec.w, this->vec.w, this->vec.w); }





onyx::math::IVec2 onyx::math::IVec2::xx() const { return IVec2(this->vec.x, this->vec.x); }
onyx::math::IVec2 onyx::math::IVec2::xy() const { return IVec2(this->vec.x, this->vec.x); }
onyx::math::IVec2 onyx::math::IVec2::yx() const { return IVec2(this->vec.x, this->vec.x); }
onyx::math::IVec2 onyx::math::IVec2::yy() const { return IVec2(this->vec.x, this->vec.x); }


onyx::math::IVec2 onyx::math::IVec3::xx() const { return IVec2(this->vec.x, this->vec.x); }
onyx::math::IVec2 onyx::math::IVec3::xy() const { return IVec2(this->vec.x, this->vec.y); }
onyx::math::IVec2 onyx::math::IVec3::xz() const { return IVec2(this->vec.x, this->vec.z); }
onyx::math::IVec2 onyx::math::IVec3::yx() const { return IVec2(this->vec.y, this->vec.x); }
onyx::math::IVec2 onyx::math::IVec3::yy() const { return IVec2(this->vec.y, this->vec.y); }
onyx::math::IVec2 onyx::math::IVec3::yz() const { return IVec2(this->vec.y, this->vec.z); }
onyx::math::IVec2 onyx::math::IVec3::zx() const { return IVec2(this->vec.z, this->vec.x); }
onyx::math::IVec2 onyx::math::IVec3::zy() const { return IVec2(this->vec.z, this->vec.y); }
onyx::math::IVec2 onyx::math::IVec3::zz() const { return IVec2(this->vec.z, this->vec.z); }

onyx::math::IVec3 onyx::math::IVec3::xxx() const { return IVec3(this->vec.x, this->vec.x, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec3::xxy() const { return IVec3(this->vec.x, this->vec.x, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec3::xxz() const { return IVec3(this->vec.x, this->vec.x, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec3::xyx() const { return IVec3(this->vec.x, this->vec.y, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec3::xyy() const { return IVec3(this->vec.x, this->vec.y, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec3::xyz() const { return IVec3(this->vec.x, this->vec.y, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec3::xzx() const { return IVec3(this->vec.x, this->vec.z, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec3::xzy() const { return IVec3(this->vec.x, this->vec.z, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec3::xzz() const { return IVec3(this->vec.x, this->vec.z, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec3::yxx() const { return IVec3(this->vec.y, this->vec.x, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec3::yxy() const { return IVec3(this->vec.y, this->vec.x, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec3::yxz() const { return IVec3(this->vec.y, this->vec.x, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec3::yyx() const { return IVec3(this->vec.y, this->vec.y, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec3::yyy() const { return IVec3(this->vec.y, this->vec.y, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec3::yyz() const { return IVec3(this->vec.y, this->vec.y, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec3::yzx() const { return IVec3(this->vec.y, this->vec.z, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec3::yzy() const { return IVec3(this->vec.y, this->vec.z, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec3::yzz() const { return IVec3(this->vec.y, this->vec.z, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec3::zxx() const { return IVec3(this->vec.z, this->vec.x, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec3::zxy() const { return IVec3(this->vec.z, this->vec.x, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec3::zxz() const { return IVec3(this->vec.z, this->vec.x, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec3::zyx() const { return IVec3(this->vec.z, this->vec.y, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec3::zyy() const { return IVec3(this->vec.z, this->vec.y, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec3::zyz() const { return IVec3(this->vec.z, this->vec.y, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec3::zzx() const { return IVec3(this->vec.z, this->vec.z, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec3::zzy() const { return IVec3(this->vec.z, this->vec.z, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec3::zzz() const { return IVec3(this->vec.z, this->vec.z, this->vec.z); }


onyx::math::IVec2 onyx::math::IVec4::xx() const { return IVec2(this->vec.x, this->vec.x); }
onyx::math::IVec2 onyx::math::IVec4::xy() const { return IVec2(this->vec.x, this->vec.y); }
onyx::math::IVec2 onyx::math::IVec4::xz() const { return IVec2(this->vec.x, this->vec.z); }
onyx::math::IVec2 onyx::math::IVec4::xw() const { return IVec2(this->vec.x, this->vec.w); }
onyx::math::IVec2 onyx::math::IVec4::yx() const { return IVec2(this->vec.y, this->vec.x); }
onyx::math::IVec2 onyx::math::IVec4::yy() const { return IVec2(this->vec.y, this->vec.y); }
onyx::math::IVec2 onyx::math::IVec4::yz() const { return IVec2(this->vec.y, this->vec.z); }
onyx::math::IVec2 onyx::math::IVec4::yw() const { return IVec2(this->vec.y, this->vec.w); }
onyx::math::IVec2 onyx::math::IVec4::zx() const { return IVec2(this->vec.z, this->vec.x); }
onyx::math::IVec2 onyx::math::IVec4::zy() const { return IVec2(this->vec.z, this->vec.y); }
onyx::math::IVec2 onyx::math::IVec4::zz() const { return IVec2(this->vec.z, this->vec.z); }
onyx::math::IVec2 onyx::math::IVec4::zw() const { return IVec2(this->vec.z, this->vec.w); }
onyx::math::IVec2 onyx::math::IVec4::wx() const { return IVec2(this->vec.w, this->vec.x); }
onyx::math::IVec2 onyx::math::IVec4::wy() const { return IVec2(this->vec.w, this->vec.y); }
onyx::math::IVec2 onyx::math::IVec4::wz() const { return IVec2(this->vec.w, this->vec.z); }
onyx::math::IVec2 onyx::math::IVec4::ww() const { return IVec2(this->vec.w, this->vec.w); }

onyx::math::IVec3 onyx::math::IVec4::xxx() const { return IVec3(this->vec.x, this->vec.x, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec4::xxy() const { return IVec3(this->vec.x, this->vec.x, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec4::xxz() const { return IVec3(this->vec.x, this->vec.x, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec4::xxw() const { return IVec3(this->vec.x, this->vec.x, this->vec.w); }
onyx::math::IVec3 onyx::math::IVec4::xyx() const { return IVec3(this->vec.x, this->vec.y, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec4::xyy() const { return IVec3(this->vec.x, this->vec.y, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec4::xyz() const { return IVec3(this->vec.x, this->vec.y, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec4::xyw() const { return IVec3(this->vec.x, this->vec.y, this->vec.w); }
onyx::math::IVec3 onyx::math::IVec4::xzx() const { return IVec3(this->vec.x, this->vec.z, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec4::xzy() const { return IVec3(this->vec.x, this->vec.z, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec4::xzz() const { return IVec3(this->vec.x, this->vec.z, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec4::xzw() const { return IVec3(this->vec.x, this->vec.z, this->vec.w); }
onyx::math::IVec3 onyx::math::IVec4::xwx() const { return IVec3(this->vec.x, this->vec.w, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec4::xwy() const { return IVec3(this->vec.x, this->vec.w, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec4::xwz() const { return IVec3(this->vec.x, this->vec.w, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec4::xww() const { return IVec3(this->vec.x, this->vec.w, this->vec.w); }
onyx::math::IVec3 onyx::math::IVec4::yxx() const { return IVec3(this->vec.y, this->vec.x, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec4::yxy() const { return IVec3(this->vec.y, this->vec.x, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec4::yxz() const { return IVec3(this->vec.y, this->vec.x, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec4::yxw() const { return IVec3(this->vec.y, this->vec.x, this->vec.w); }
onyx::math::IVec3 onyx::math::IVec4::yyx() const { return IVec3(this->vec.y, this->vec.y, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec4::yyy() const { return IVec3(this->vec.y, this->vec.y, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec4::yyz() const { return IVec3(this->vec.y, this->vec.y, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec4::yyw() const { return IVec3(this->vec.y, this->vec.y, this->vec.w); }
onyx::math::IVec3 onyx::math::IVec4::yzx() const { return IVec3(this->vec.y, this->vec.z, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec4::yzy() const { return IVec3(this->vec.y, this->vec.z, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec4::yzz() const { return IVec3(this->vec.y, this->vec.z, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec4::yzw() const { return IVec3(this->vec.y, this->vec.z, this->vec.w); }
onyx::math::IVec3 onyx::math::IVec4::ywx() const { return IVec3(this->vec.y, this->vec.w, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec4::ywy() const { return IVec3(this->vec.y, this->vec.w, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec4::ywz() const { return IVec3(this->vec.y, this->vec.w, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec4::yww() const { return IVec3(this->vec.y, this->vec.w, this->vec.w); }
onyx::math::IVec3 onyx::math::IVec4::zxx() const { return IVec3(this->vec.z, this->vec.x, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec4::zxy() const { return IVec3(this->vec.z, this->vec.x, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec4::zxz() const { return IVec3(this->vec.z, this->vec.x, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec4::zxw() const { return IVec3(this->vec.z, this->vec.x, this->vec.w); }
onyx::math::IVec3 onyx::math::IVec4::zyx() const { return IVec3(this->vec.z, this->vec.y, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec4::zyy() const { return IVec3(this->vec.z, this->vec.y, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec4::zyz() const { return IVec3(this->vec.z, this->vec.y, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec4::zyw() const { return IVec3(this->vec.z, this->vec.y, this->vec.w); }
onyx::math::IVec3 onyx::math::IVec4::zzx() const { return IVec3(this->vec.z, this->vec.z, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec4::zzy() const { return IVec3(this->vec.z, this->vec.z, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec4::zzz() const { return IVec3(this->vec.z, this->vec.z, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec4::zzw() const { return IVec3(this->vec.z, this->vec.z, this->vec.w); }
onyx::math::IVec3 onyx::math::IVec4::zwx() const { return IVec3(this->vec.z, this->vec.w, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec4::zwy() const { return IVec3(this->vec.z, this->vec.w, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec4::zwz() const { return IVec3(this->vec.z, this->vec.w, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec4::zww() const { return IVec3(this->vec.z, this->vec.w, this->vec.w); }
onyx::math::IVec3 onyx::math::IVec4::wxx() const { return IVec3(this->vec.w, this->vec.x, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec4::wxy() const { return IVec3(this->vec.w, this->vec.x, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec4::wxz() const { return IVec3(this->vec.w, this->vec.x, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec4::wxw() const { return IVec3(this->vec.w, this->vec.x, this->vec.w); }
onyx::math::IVec3 onyx::math::IVec4::wyx() const { return IVec3(this->vec.w, this->vec.y, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec4::wyy() const { return IVec3(this->vec.w, this->vec.y, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec4::wyz() const { return IVec3(this->vec.w, this->vec.y, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec4::wyw() const { return IVec3(this->vec.w, this->vec.y, this->vec.w); }
onyx::math::IVec3 onyx::math::IVec4::wzx() const { return IVec3(this->vec.w, this->vec.z, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec4::wzy() const { return IVec3(this->vec.w, this->vec.z, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec4::wzz() const { return IVec3(this->vec.w, this->vec.z, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec4::wzw() const { return IVec3(this->vec.w, this->vec.z, this->vec.w); }
onyx::math::IVec3 onyx::math::IVec4::wwx() const { return IVec3(this->vec.w, this->vec.w, this->vec.x); }
onyx::math::IVec3 onyx::math::IVec4::wwy() const { return IVec3(this->vec.w, this->vec.w, this->vec.y); }
onyx::math::IVec3 onyx::math::IVec4::wwz() const { return IVec3(this->vec.w, this->vec.w, this->vec.z); }
onyx::math::IVec3 onyx::math::IVec4::www() const { return IVec3(this->vec.w, this->vec.w, this->vec.w); }

onyx::math::IVec4 onyx::math::IVec4::xxxx() const { return IVec4(this->vec.x, this->vec.x, this->vec.x, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::xxxy() const { return IVec4(this->vec.x, this->vec.x, this->vec.x, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::xxxz() const { return IVec4(this->vec.x, this->vec.x, this->vec.x, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::xxxw() const { return IVec4(this->vec.x, this->vec.x, this->vec.x, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::xxyx() const { return IVec4(this->vec.x, this->vec.x, this->vec.y, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::xxyy() const { return IVec4(this->vec.x, this->vec.x, this->vec.y, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::xxyz() const { return IVec4(this->vec.x, this->vec.x, this->vec.y, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::xxyw() const { return IVec4(this->vec.x, this->vec.x, this->vec.y, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::xxzx() const { return IVec4(this->vec.x, this->vec.x, this->vec.z, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::xxzy() const { return IVec4(this->vec.x, this->vec.x, this->vec.z, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::xxzz() const { return IVec4(this->vec.x, this->vec.x, this->vec.z, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::xxzw() const { return IVec4(this->vec.x, this->vec.x, this->vec.z, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::xxwx() const { return IVec4(this->vec.x, this->vec.x, this->vec.w, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::xxwy() const { return IVec4(this->vec.x, this->vec.x, this->vec.w, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::xxwz() const { return IVec4(this->vec.x, this->vec.x, this->vec.w, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::xxww() const { return IVec4(this->vec.x, this->vec.x, this->vec.w, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::xyxx() const { return IVec4(this->vec.x, this->vec.y, this->vec.x, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::xyxy() const { return IVec4(this->vec.x, this->vec.y, this->vec.x, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::xyxz() const { return IVec4(this->vec.x, this->vec.y, this->vec.x, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::xyxw() const { return IVec4(this->vec.x, this->vec.y, this->vec.x, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::xyyx() const { return IVec4(this->vec.x, this->vec.y, this->vec.y, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::xyyy() const { return IVec4(this->vec.x, this->vec.y, this->vec.y, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::xyyz() const { return IVec4(this->vec.x, this->vec.y, this->vec.y, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::xyyw() const { return IVec4(this->vec.x, this->vec.y, this->vec.y, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::xyzx() const { return IVec4(this->vec.x, this->vec.y, this->vec.z, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::xyzy() const { return IVec4(this->vec.x, this->vec.y, this->vec.z, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::xyzz() const { return IVec4(this->vec.x, this->vec.y, this->vec.z, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::xyzw() const { return IVec4(this->vec.x, this->vec.y, this->vec.z, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::xywx() const { return IVec4(this->vec.x, this->vec.y, this->vec.w, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::xywy() const { return IVec4(this->vec.x, this->vec.y, this->vec.w, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::xywz() const { return IVec4(this->vec.x, this->vec.y, this->vec.w, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::xyww() const { return IVec4(this->vec.x, this->vec.y, this->vec.w, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::xzxx() const { return IVec4(this->vec.x, this->vec.z, this->vec.x, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::xzxy() const { return IVec4(this->vec.x, this->vec.z, this->vec.x, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::xzxz() const { return IVec4(this->vec.x, this->vec.z, this->vec.x, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::xzxw() const { return IVec4(this->vec.x, this->vec.z, this->vec.x, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::xzyx() const { return IVec4(this->vec.x, this->vec.z, this->vec.y, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::xzyy() const { return IVec4(this->vec.x, this->vec.z, this->vec.y, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::xzyz() const { return IVec4(this->vec.x, this->vec.z, this->vec.y, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::xzyw() const { return IVec4(this->vec.x, this->vec.z, this->vec.y, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::xzzx() const { return IVec4(this->vec.x, this->vec.z, this->vec.z, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::xzzy() const { return IVec4(this->vec.x, this->vec.z, this->vec.z, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::xzzz() const { return IVec4(this->vec.x, this->vec.z, this->vec.z, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::xzzw() const { return IVec4(this->vec.x, this->vec.z, this->vec.z, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::xzwx() const { return IVec4(this->vec.x, this->vec.z, this->vec.w, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::xzwy() const { return IVec4(this->vec.x, this->vec.z, this->vec.w, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::xzwz() const { return IVec4(this->vec.x, this->vec.z, this->vec.w, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::xzww() const { return IVec4(this->vec.x, this->vec.z, this->vec.w, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::xwxx() const { return IVec4(this->vec.x, this->vec.w, this->vec.x, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::xwxy() const { return IVec4(this->vec.x, this->vec.w, this->vec.x, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::xwxz() const { return IVec4(this->vec.x, this->vec.w, this->vec.x, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::xwxw() const { return IVec4(this->vec.x, this->vec.w, this->vec.x, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::xwyx() const { return IVec4(this->vec.x, this->vec.w, this->vec.y, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::xwyy() const { return IVec4(this->vec.x, this->vec.w, this->vec.y, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::xwyz() const { return IVec4(this->vec.x, this->vec.w, this->vec.y, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::xwyw() const { return IVec4(this->vec.x, this->vec.w, this->vec.y, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::xwzx() const { return IVec4(this->vec.x, this->vec.w, this->vec.z, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::xwzy() const { return IVec4(this->vec.x, this->vec.w, this->vec.z, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::xwzz() const { return IVec4(this->vec.x, this->vec.w, this->vec.z, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::xwzw() const { return IVec4(this->vec.x, this->vec.w, this->vec.z, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::xwwx() const { return IVec4(this->vec.x, this->vec.w, this->vec.w, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::xwwy() const { return IVec4(this->vec.x, this->vec.w, this->vec.w, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::xwwz() const { return IVec4(this->vec.x, this->vec.w, this->vec.w, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::xwww() const { return IVec4(this->vec.x, this->vec.w, this->vec.w, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::yxxx() const { return IVec4(this->vec.y, this->vec.x, this->vec.x, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::yxxy() const { return IVec4(this->vec.y, this->vec.x, this->vec.x, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::yxxz() const { return IVec4(this->vec.y, this->vec.x, this->vec.x, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::yxxw() const { return IVec4(this->vec.y, this->vec.x, this->vec.x, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::yxyx() const { return IVec4(this->vec.y, this->vec.x, this->vec.y, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::yxyy() const { return IVec4(this->vec.y, this->vec.x, this->vec.y, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::yxyz() const { return IVec4(this->vec.y, this->vec.x, this->vec.y, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::yxyw() const { return IVec4(this->vec.y, this->vec.x, this->vec.y, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::yxzx() const { return IVec4(this->vec.y, this->vec.x, this->vec.z, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::yxzy() const { return IVec4(this->vec.y, this->vec.x, this->vec.z, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::yxzz() const { return IVec4(this->vec.y, this->vec.x, this->vec.z, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::yxzw() const { return IVec4(this->vec.y, this->vec.x, this->vec.z, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::yxwx() const { return IVec4(this->vec.y, this->vec.x, this->vec.w, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::yxwy() const { return IVec4(this->vec.y, this->vec.x, this->vec.w, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::yxwz() const { return IVec4(this->vec.y, this->vec.x, this->vec.w, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::yxww() const { return IVec4(this->vec.y, this->vec.x, this->vec.w, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::yyxx() const { return IVec4(this->vec.y, this->vec.y, this->vec.x, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::yyxy() const { return IVec4(this->vec.y, this->vec.y, this->vec.x, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::yyxz() const { return IVec4(this->vec.y, this->vec.y, this->vec.x, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::yyxw() const { return IVec4(this->vec.y, this->vec.y, this->vec.x, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::yyyx() const { return IVec4(this->vec.y, this->vec.y, this->vec.y, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::yyyy() const { return IVec4(this->vec.y, this->vec.y, this->vec.y, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::yyyz() const { return IVec4(this->vec.y, this->vec.y, this->vec.y, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::yyyw() const { return IVec4(this->vec.y, this->vec.y, this->vec.y, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::yyzx() const { return IVec4(this->vec.y, this->vec.y, this->vec.z, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::yyzy() const { return IVec4(this->vec.y, this->vec.y, this->vec.z, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::yyzz() const { return IVec4(this->vec.y, this->vec.y, this->vec.z, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::yyzw() const { return IVec4(this->vec.y, this->vec.y, this->vec.z, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::yywx() const { return IVec4(this->vec.y, this->vec.y, this->vec.w, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::yywy() const { return IVec4(this->vec.y, this->vec.y, this->vec.w, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::yywz() const { return IVec4(this->vec.y, this->vec.y, this->vec.w, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::yyww() const { return IVec4(this->vec.y, this->vec.y, this->vec.w, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::yzxx() const { return IVec4(this->vec.y, this->vec.z, this->vec.x, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::yzxy() const { return IVec4(this->vec.y, this->vec.z, this->vec.x, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::yzxz() const { return IVec4(this->vec.y, this->vec.z, this->vec.x, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::yzxw() const { return IVec4(this->vec.y, this->vec.z, this->vec.x, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::yzyx() const { return IVec4(this->vec.y, this->vec.z, this->vec.y, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::yzyy() const { return IVec4(this->vec.y, this->vec.z, this->vec.y, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::yzyz() const { return IVec4(this->vec.y, this->vec.z, this->vec.y, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::yzyw() const { return IVec4(this->vec.y, this->vec.z, this->vec.y, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::yzzx() const { return IVec4(this->vec.y, this->vec.z, this->vec.z, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::yzzy() const { return IVec4(this->vec.y, this->vec.z, this->vec.z, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::yzzz() const { return IVec4(this->vec.y, this->vec.z, this->vec.z, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::yzzw() const { return IVec4(this->vec.y, this->vec.z, this->vec.z, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::yzwx() const { return IVec4(this->vec.y, this->vec.z, this->vec.w, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::yzwy() const { return IVec4(this->vec.y, this->vec.z, this->vec.w, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::yzwz() const { return IVec4(this->vec.y, this->vec.z, this->vec.w, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::yzww() const { return IVec4(this->vec.y, this->vec.z, this->vec.w, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::ywxx() const { return IVec4(this->vec.y, this->vec.w, this->vec.x, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::ywxy() const { return IVec4(this->vec.y, this->vec.w, this->vec.x, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::ywxz() const { return IVec4(this->vec.y, this->vec.w, this->vec.x, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::ywxw() const { return IVec4(this->vec.y, this->vec.w, this->vec.x, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::ywyx() const { return IVec4(this->vec.y, this->vec.w, this->vec.y, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::ywyy() const { return IVec4(this->vec.y, this->vec.w, this->vec.y, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::ywyz() const { return IVec4(this->vec.y, this->vec.w, this->vec.y, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::ywyw() const { return IVec4(this->vec.y, this->vec.w, this->vec.y, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::ywzx() const { return IVec4(this->vec.y, this->vec.w, this->vec.z, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::ywzy() const { return IVec4(this->vec.y, this->vec.w, this->vec.z, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::ywzz() const { return IVec4(this->vec.y, this->vec.w, this->vec.z, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::ywzw() const { return IVec4(this->vec.y, this->vec.w, this->vec.z, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::ywwx() const { return IVec4(this->vec.y, this->vec.w, this->vec.w, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::ywwy() const { return IVec4(this->vec.y, this->vec.w, this->vec.w, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::ywwz() const { return IVec4(this->vec.y, this->vec.w, this->vec.w, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::ywww() const { return IVec4(this->vec.y, this->vec.w, this->vec.w, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::zxxx() const { return IVec4(this->vec.z, this->vec.x, this->vec.x, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::zxxy() const { return IVec4(this->vec.z, this->vec.x, this->vec.x, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::zxxz() const { return IVec4(this->vec.z, this->vec.x, this->vec.x, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::zxxw() const { return IVec4(this->vec.z, this->vec.x, this->vec.x, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::zxyx() const { return IVec4(this->vec.z, this->vec.x, this->vec.y, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::zxyy() const { return IVec4(this->vec.z, this->vec.x, this->vec.y, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::zxyz() const { return IVec4(this->vec.z, this->vec.x, this->vec.y, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::zxyw() const { return IVec4(this->vec.z, this->vec.x, this->vec.y, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::zxzx() const { return IVec4(this->vec.z, this->vec.x, this->vec.z, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::zxzy() const { return IVec4(this->vec.z, this->vec.x, this->vec.z, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::zxzz() const { return IVec4(this->vec.z, this->vec.x, this->vec.z, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::zxzw() const { return IVec4(this->vec.z, this->vec.x, this->vec.z, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::zxwx() const { return IVec4(this->vec.z, this->vec.x, this->vec.w, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::zxwy() const { return IVec4(this->vec.z, this->vec.x, this->vec.w, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::zxwz() const { return IVec4(this->vec.z, this->vec.x, this->vec.w, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::zxww() const { return IVec4(this->vec.z, this->vec.x, this->vec.w, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::zyxx() const { return IVec4(this->vec.z, this->vec.y, this->vec.x, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::zyxy() const { return IVec4(this->vec.z, this->vec.y, this->vec.x, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::zyxz() const { return IVec4(this->vec.z, this->vec.y, this->vec.x, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::zyxw() const { return IVec4(this->vec.z, this->vec.y, this->vec.x, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::zyyx() const { return IVec4(this->vec.z, this->vec.y, this->vec.y, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::zyyy() const { return IVec4(this->vec.z, this->vec.y, this->vec.y, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::zyyz() const { return IVec4(this->vec.z, this->vec.y, this->vec.y, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::zyyw() const { return IVec4(this->vec.z, this->vec.y, this->vec.y, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::zyzx() const { return IVec4(this->vec.z, this->vec.y, this->vec.z, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::zyzy() const { return IVec4(this->vec.z, this->vec.y, this->vec.z, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::zyzz() const { return IVec4(this->vec.z, this->vec.y, this->vec.z, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::zyzw() const { return IVec4(this->vec.z, this->vec.y, this->vec.z, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::zywx() const { return IVec4(this->vec.z, this->vec.y, this->vec.w, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::zywy() const { return IVec4(this->vec.z, this->vec.y, this->vec.w, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::zywz() const { return IVec4(this->vec.z, this->vec.y, this->vec.w, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::zyww() const { return IVec4(this->vec.z, this->vec.y, this->vec.w, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::zzxx() const { return IVec4(this->vec.z, this->vec.z, this->vec.x, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::zzxy() const { return IVec4(this->vec.z, this->vec.z, this->vec.x, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::zzxz() const { return IVec4(this->vec.z, this->vec.z, this->vec.x, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::zzxw() const { return IVec4(this->vec.z, this->vec.z, this->vec.x, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::zzyx() const { return IVec4(this->vec.z, this->vec.z, this->vec.y, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::zzyy() const { return IVec4(this->vec.z, this->vec.z, this->vec.y, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::zzyz() const { return IVec4(this->vec.z, this->vec.z, this->vec.y, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::zzyw() const { return IVec4(this->vec.z, this->vec.z, this->vec.y, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::zzzx() const { return IVec4(this->vec.z, this->vec.z, this->vec.z, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::zzzy() const { return IVec4(this->vec.z, this->vec.z, this->vec.z, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::zzzz() const { return IVec4(this->vec.z, this->vec.z, this->vec.z, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::zzzw() const { return IVec4(this->vec.z, this->vec.z, this->vec.z, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::zzwx() const { return IVec4(this->vec.z, this->vec.z, this->vec.w, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::zzwy() const { return IVec4(this->vec.z, this->vec.z, this->vec.w, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::zzwz() const { return IVec4(this->vec.z, this->vec.z, this->vec.w, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::zzww() const { return IVec4(this->vec.z, this->vec.z, this->vec.w, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::zwxx() const { return IVec4(this->vec.z, this->vec.w, this->vec.x, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::zwxy() const { return IVec4(this->vec.z, this->vec.w, this->vec.x, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::zwxz() const { return IVec4(this->vec.z, this->vec.w, this->vec.x, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::zwxw() const { return IVec4(this->vec.z, this->vec.w, this->vec.x, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::zwyx() const { return IVec4(this->vec.z, this->vec.w, this->vec.y, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::zwyy() const { return IVec4(this->vec.z, this->vec.w, this->vec.y, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::zwyz() const { return IVec4(this->vec.z, this->vec.w, this->vec.y, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::zwyw() const { return IVec4(this->vec.z, this->vec.w, this->vec.y, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::zwzx() const { return IVec4(this->vec.z, this->vec.w, this->vec.z, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::zwzy() const { return IVec4(this->vec.z, this->vec.w, this->vec.z, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::zwzz() const { return IVec4(this->vec.z, this->vec.w, this->vec.z, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::zwzw() const { return IVec4(this->vec.z, this->vec.w, this->vec.z, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::zwwx() const { return IVec4(this->vec.z, this->vec.w, this->vec.w, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::zwwy() const { return IVec4(this->vec.z, this->vec.w, this->vec.w, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::zwwz() const { return IVec4(this->vec.z, this->vec.w, this->vec.w, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::zwww() const { return IVec4(this->vec.z, this->vec.w, this->vec.w, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::wxxx() const { return IVec4(this->vec.w, this->vec.x, this->vec.x, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::wxxy() const { return IVec4(this->vec.w, this->vec.x, this->vec.x, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::wxxz() const { return IVec4(this->vec.w, this->vec.x, this->vec.x, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::wxxw() const { return IVec4(this->vec.w, this->vec.x, this->vec.x, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::wxyx() const { return IVec4(this->vec.w, this->vec.x, this->vec.y, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::wxyy() const { return IVec4(this->vec.w, this->vec.x, this->vec.y, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::wxyz() const { return IVec4(this->vec.w, this->vec.x, this->vec.y, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::wxyw() const { return IVec4(this->vec.w, this->vec.x, this->vec.y, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::wxzx() const { return IVec4(this->vec.w, this->vec.x, this->vec.z, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::wxzy() const { return IVec4(this->vec.w, this->vec.x, this->vec.z, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::wxzz() const { return IVec4(this->vec.w, this->vec.x, this->vec.z, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::wxzw() const { return IVec4(this->vec.w, this->vec.x, this->vec.z, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::wxwx() const { return IVec4(this->vec.w, this->vec.x, this->vec.w, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::wxwy() const { return IVec4(this->vec.w, this->vec.x, this->vec.w, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::wxwz() const { return IVec4(this->vec.w, this->vec.x, this->vec.w, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::wxww() const { return IVec4(this->vec.w, this->vec.x, this->vec.w, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::wyxx() const { return IVec4(this->vec.w, this->vec.y, this->vec.x, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::wyxy() const { return IVec4(this->vec.w, this->vec.y, this->vec.x, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::wyxz() const { return IVec4(this->vec.w, this->vec.y, this->vec.x, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::wyxw() const { return IVec4(this->vec.w, this->vec.y, this->vec.x, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::wyyx() const { return IVec4(this->vec.w, this->vec.y, this->vec.y, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::wyyy() const { return IVec4(this->vec.w, this->vec.y, this->vec.y, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::wyyz() const { return IVec4(this->vec.w, this->vec.y, this->vec.y, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::wyyw() const { return IVec4(this->vec.w, this->vec.y, this->vec.y, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::wyzx() const { return IVec4(this->vec.w, this->vec.y, this->vec.z, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::wyzy() const { return IVec4(this->vec.w, this->vec.y, this->vec.z, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::wyzz() const { return IVec4(this->vec.w, this->vec.y, this->vec.z, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::wyzw() const { return IVec4(this->vec.w, this->vec.y, this->vec.z, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::wywx() const { return IVec4(this->vec.w, this->vec.y, this->vec.w, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::wywy() const { return IVec4(this->vec.w, this->vec.y, this->vec.w, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::wywz() const { return IVec4(this->vec.w, this->vec.y, this->vec.w, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::wyww() const { return IVec4(this->vec.w, this->vec.y, this->vec.w, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::wzxx() const { return IVec4(this->vec.w, this->vec.z, this->vec.x, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::wzxy() const { return IVec4(this->vec.w, this->vec.z, this->vec.x, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::wzxz() const { return IVec4(this->vec.w, this->vec.z, this->vec.x, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::wzxw() const { return IVec4(this->vec.w, this->vec.z, this->vec.x, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::wzyx() const { return IVec4(this->vec.w, this->vec.z, this->vec.y, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::wzyy() const { return IVec4(this->vec.w, this->vec.z, this->vec.y, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::wzyz() const { return IVec4(this->vec.w, this->vec.z, this->vec.y, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::wzyw() const { return IVec4(this->vec.w, this->vec.z, this->vec.y, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::wzzx() const { return IVec4(this->vec.w, this->vec.z, this->vec.z, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::wzzy() const { return IVec4(this->vec.w, this->vec.z, this->vec.z, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::wzzz() const { return IVec4(this->vec.w, this->vec.z, this->vec.z, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::wzzw() const { return IVec4(this->vec.w, this->vec.z, this->vec.z, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::wzwx() const { return IVec4(this->vec.w, this->vec.z, this->vec.w, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::wzwy() const { return IVec4(this->vec.w, this->vec.z, this->vec.w, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::wzwz() const { return IVec4(this->vec.w, this->vec.z, this->vec.w, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::wzww() const { return IVec4(this->vec.w, this->vec.z, this->vec.w, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::wwxx() const { return IVec4(this->vec.w, this->vec.w, this->vec.x, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::wwxy() const { return IVec4(this->vec.w, this->vec.w, this->vec.x, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::wwxz() const { return IVec4(this->vec.w, this->vec.w, this->vec.x, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::wwxw() const { return IVec4(this->vec.w, this->vec.w, this->vec.x, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::wwyx() const { return IVec4(this->vec.w, this->vec.w, this->vec.y, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::wwyy() const { return IVec4(this->vec.w, this->vec.w, this->vec.y, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::wwyz() const { return IVec4(this->vec.w, this->vec.w, this->vec.y, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::wwyw() const { return IVec4(this->vec.w, this->vec.w, this->vec.y, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::wwzx() const { return IVec4(this->vec.w, this->vec.w, this->vec.z, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::wwzy() const { return IVec4(this->vec.w, this->vec.w, this->vec.z, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::wwzz() const { return IVec4(this->vec.w, this->vec.w, this->vec.z, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::wwzw() const { return IVec4(this->vec.w, this->vec.w, this->vec.z, this->vec.w); }
onyx::math::IVec4 onyx::math::IVec4::wwwx() const { return IVec4(this->vec.w, this->vec.w, this->vec.w, this->vec.x); }
onyx::math::IVec4 onyx::math::IVec4::wwwy() const { return IVec4(this->vec.w, this->vec.w, this->vec.w, this->vec.y); }
onyx::math::IVec4 onyx::math::IVec4::wwwz() const { return IVec4(this->vec.w, this->vec.w, this->vec.w, this->vec.z); }
onyx::math::IVec4 onyx::math::IVec4::wwww() const { return IVec4(this->vec.w, this->vec.w, this->vec.w, this->vec.w); }





onyx::math::UVec2 onyx::math::UVec2::xx() const { return UVec2(this->vec.x, this->vec.x); }
onyx::math::UVec2 onyx::math::UVec2::xy() const { return UVec2(this->vec.x, this->vec.x); }
onyx::math::UVec2 onyx::math::UVec2::yx() const { return UVec2(this->vec.x, this->vec.x); }
onyx::math::UVec2 onyx::math::UVec2::yy() const { return UVec2(this->vec.x, this->vec.x); }


onyx::math::UVec2 onyx::math::UVec3::xx() const { return UVec2(this->vec.x, this->vec.x); }
onyx::math::UVec2 onyx::math::UVec3::xy() const { return UVec2(this->vec.x, this->vec.y); }
onyx::math::UVec2 onyx::math::UVec3::xz() const { return UVec2(this->vec.x, this->vec.z); }
onyx::math::UVec2 onyx::math::UVec3::yx() const { return UVec2(this->vec.y, this->vec.x); }
onyx::math::UVec2 onyx::math::UVec3::yy() const { return UVec2(this->vec.y, this->vec.y); }
onyx::math::UVec2 onyx::math::UVec3::yz() const { return UVec2(this->vec.y, this->vec.z); }
onyx::math::UVec2 onyx::math::UVec3::zx() const { return UVec2(this->vec.z, this->vec.x); }
onyx::math::UVec2 onyx::math::UVec3::zy() const { return UVec2(this->vec.z, this->vec.y); }
onyx::math::UVec2 onyx::math::UVec3::zz() const { return UVec2(this->vec.z, this->vec.z); }

onyx::math::UVec3 onyx::math::UVec3::xxx() const { return UVec3(this->vec.x, this->vec.x, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec3::xxy() const { return UVec3(this->vec.x, this->vec.x, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec3::xxz() const { return UVec3(this->vec.x, this->vec.x, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec3::xyx() const { return UVec3(this->vec.x, this->vec.y, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec3::xyy() const { return UVec3(this->vec.x, this->vec.y, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec3::xyz() const { return UVec3(this->vec.x, this->vec.y, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec3::xzx() const { return UVec3(this->vec.x, this->vec.z, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec3::xzy() const { return UVec3(this->vec.x, this->vec.z, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec3::xzz() const { return UVec3(this->vec.x, this->vec.z, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec3::yxx() const { return UVec3(this->vec.y, this->vec.x, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec3::yxy() const { return UVec3(this->vec.y, this->vec.x, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec3::yxz() const { return UVec3(this->vec.y, this->vec.x, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec3::yyx() const { return UVec3(this->vec.y, this->vec.y, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec3::yyy() const { return UVec3(this->vec.y, this->vec.y, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec3::yyz() const { return UVec3(this->vec.y, this->vec.y, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec3::yzx() const { return UVec3(this->vec.y, this->vec.z, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec3::yzy() const { return UVec3(this->vec.y, this->vec.z, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec3::yzz() const { return UVec3(this->vec.y, this->vec.z, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec3::zxx() const { return UVec3(this->vec.z, this->vec.x, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec3::zxy() const { return UVec3(this->vec.z, this->vec.x, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec3::zxz() const { return UVec3(this->vec.z, this->vec.x, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec3::zyx() const { return UVec3(this->vec.z, this->vec.y, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec3::zyy() const { return UVec3(this->vec.z, this->vec.y, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec3::zyz() const { return UVec3(this->vec.z, this->vec.y, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec3::zzx() const { return UVec3(this->vec.z, this->vec.z, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec3::zzy() const { return UVec3(this->vec.z, this->vec.z, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec3::zzz() const { return UVec3(this->vec.z, this->vec.z, this->vec.z); }


onyx::math::UVec2 onyx::math::UVec4::xx() const { return UVec2(this->vec.x, this->vec.x); }
onyx::math::UVec2 onyx::math::UVec4::xy() const { return UVec2(this->vec.x, this->vec.y); }
onyx::math::UVec2 onyx::math::UVec4::xz() const { return UVec2(this->vec.x, this->vec.z); }
onyx::math::UVec2 onyx::math::UVec4::xw() const { return UVec2(this->vec.x, this->vec.w); }
onyx::math::UVec2 onyx::math::UVec4::yx() const { return UVec2(this->vec.y, this->vec.x); }
onyx::math::UVec2 onyx::math::UVec4::yy() const { return UVec2(this->vec.y, this->vec.y); }
onyx::math::UVec2 onyx::math::UVec4::yz() const { return UVec2(this->vec.y, this->vec.z); }
onyx::math::UVec2 onyx::math::UVec4::yw() const { return UVec2(this->vec.y, this->vec.w); }
onyx::math::UVec2 onyx::math::UVec4::zx() const { return UVec2(this->vec.z, this->vec.x); }
onyx::math::UVec2 onyx::math::UVec4::zy() const { return UVec2(this->vec.z, this->vec.y); }
onyx::math::UVec2 onyx::math::UVec4::zz() const { return UVec2(this->vec.z, this->vec.z); }
onyx::math::UVec2 onyx::math::UVec4::zw() const { return UVec2(this->vec.z, this->vec.w); }
onyx::math::UVec2 onyx::math::UVec4::wx() const { return UVec2(this->vec.w, this->vec.x); }
onyx::math::UVec2 onyx::math::UVec4::wy() const { return UVec2(this->vec.w, this->vec.y); }
onyx::math::UVec2 onyx::math::UVec4::wz() const { return UVec2(this->vec.w, this->vec.z); }
onyx::math::UVec2 onyx::math::UVec4::ww() const { return UVec2(this->vec.w, this->vec.w); }

onyx::math::UVec3 onyx::math::UVec4::xxx() const { return UVec3(this->vec.x, this->vec.x, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec4::xxy() const { return UVec3(this->vec.x, this->vec.x, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec4::xxz() const { return UVec3(this->vec.x, this->vec.x, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec4::xxw() const { return UVec3(this->vec.x, this->vec.x, this->vec.w); }
onyx::math::UVec3 onyx::math::UVec4::xyx() const { return UVec3(this->vec.x, this->vec.y, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec4::xyy() const { return UVec3(this->vec.x, this->vec.y, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec4::xyz() const { return UVec3(this->vec.x, this->vec.y, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec4::xyw() const { return UVec3(this->vec.x, this->vec.y, this->vec.w); }
onyx::math::UVec3 onyx::math::UVec4::xzx() const { return UVec3(this->vec.x, this->vec.z, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec4::xzy() const { return UVec3(this->vec.x, this->vec.z, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec4::xzz() const { return UVec3(this->vec.x, this->vec.z, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec4::xzw() const { return UVec3(this->vec.x, this->vec.z, this->vec.w); }
onyx::math::UVec3 onyx::math::UVec4::xwx() const { return UVec3(this->vec.x, this->vec.w, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec4::xwy() const { return UVec3(this->vec.x, this->vec.w, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec4::xwz() const { return UVec3(this->vec.x, this->vec.w, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec4::xww() const { return UVec3(this->vec.x, this->vec.w, this->vec.w); }
onyx::math::UVec3 onyx::math::UVec4::yxx() const { return UVec3(this->vec.y, this->vec.x, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec4::yxy() const { return UVec3(this->vec.y, this->vec.x, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec4::yxz() const { return UVec3(this->vec.y, this->vec.x, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec4::yxw() const { return UVec3(this->vec.y, this->vec.x, this->vec.w); }
onyx::math::UVec3 onyx::math::UVec4::yyx() const { return UVec3(this->vec.y, this->vec.y, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec4::yyy() const { return UVec3(this->vec.y, this->vec.y, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec4::yyz() const { return UVec3(this->vec.y, this->vec.y, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec4::yyw() const { return UVec3(this->vec.y, this->vec.y, this->vec.w); }
onyx::math::UVec3 onyx::math::UVec4::yzx() const { return UVec3(this->vec.y, this->vec.z, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec4::yzy() const { return UVec3(this->vec.y, this->vec.z, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec4::yzz() const { return UVec3(this->vec.y, this->vec.z, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec4::yzw() const { return UVec3(this->vec.y, this->vec.z, this->vec.w); }
onyx::math::UVec3 onyx::math::UVec4::ywx() const { return UVec3(this->vec.y, this->vec.w, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec4::ywy() const { return UVec3(this->vec.y, this->vec.w, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec4::ywz() const { return UVec3(this->vec.y, this->vec.w, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec4::yww() const { return UVec3(this->vec.y, this->vec.w, this->vec.w); }
onyx::math::UVec3 onyx::math::UVec4::zxx() const { return UVec3(this->vec.z, this->vec.x, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec4::zxy() const { return UVec3(this->vec.z, this->vec.x, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec4::zxz() const { return UVec3(this->vec.z, this->vec.x, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec4::zxw() const { return UVec3(this->vec.z, this->vec.x, this->vec.w); }
onyx::math::UVec3 onyx::math::UVec4::zyx() const { return UVec3(this->vec.z, this->vec.y, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec4::zyy() const { return UVec3(this->vec.z, this->vec.y, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec4::zyz() const { return UVec3(this->vec.z, this->vec.y, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec4::zyw() const { return UVec3(this->vec.z, this->vec.y, this->vec.w); }
onyx::math::UVec3 onyx::math::UVec4::zzx() const { return UVec3(this->vec.z, this->vec.z, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec4::zzy() const { return UVec3(this->vec.z, this->vec.z, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec4::zzz() const { return UVec3(this->vec.z, this->vec.z, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec4::zzw() const { return UVec3(this->vec.z, this->vec.z, this->vec.w); }
onyx::math::UVec3 onyx::math::UVec4::zwx() const { return UVec3(this->vec.z, this->vec.w, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec4::zwy() const { return UVec3(this->vec.z, this->vec.w, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec4::zwz() const { return UVec3(this->vec.z, this->vec.w, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec4::zww() const { return UVec3(this->vec.z, this->vec.w, this->vec.w); }
onyx::math::UVec3 onyx::math::UVec4::wxx() const { return UVec3(this->vec.w, this->vec.x, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec4::wxy() const { return UVec3(this->vec.w, this->vec.x, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec4::wxz() const { return UVec3(this->vec.w, this->vec.x, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec4::wxw() const { return UVec3(this->vec.w, this->vec.x, this->vec.w); }
onyx::math::UVec3 onyx::math::UVec4::wyx() const { return UVec3(this->vec.w, this->vec.y, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec4::wyy() const { return UVec3(this->vec.w, this->vec.y, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec4::wyz() const { return UVec3(this->vec.w, this->vec.y, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec4::wyw() const { return UVec3(this->vec.w, this->vec.y, this->vec.w); }
onyx::math::UVec3 onyx::math::UVec4::wzx() const { return UVec3(this->vec.w, this->vec.z, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec4::wzy() const { return UVec3(this->vec.w, this->vec.z, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec4::wzz() const { return UVec3(this->vec.w, this->vec.z, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec4::wzw() const { return UVec3(this->vec.w, this->vec.z, this->vec.w); }
onyx::math::UVec3 onyx::math::UVec4::wwx() const { return UVec3(this->vec.w, this->vec.w, this->vec.x); }
onyx::math::UVec3 onyx::math::UVec4::wwy() const { return UVec3(this->vec.w, this->vec.w, this->vec.y); }
onyx::math::UVec3 onyx::math::UVec4::wwz() const { return UVec3(this->vec.w, this->vec.w, this->vec.z); }
onyx::math::UVec3 onyx::math::UVec4::www() const { return UVec3(this->vec.w, this->vec.w, this->vec.w); }

onyx::math::UVec4 onyx::math::UVec4::xxxx() const { return UVec4(this->vec.x, this->vec.x, this->vec.x, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::xxxy() const { return UVec4(this->vec.x, this->vec.x, this->vec.x, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::xxxz() const { return UVec4(this->vec.x, this->vec.x, this->vec.x, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::xxxw() const { return UVec4(this->vec.x, this->vec.x, this->vec.x, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::xxyx() const { return UVec4(this->vec.x, this->vec.x, this->vec.y, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::xxyy() const { return UVec4(this->vec.x, this->vec.x, this->vec.y, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::xxyz() const { return UVec4(this->vec.x, this->vec.x, this->vec.y, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::xxyw() const { return UVec4(this->vec.x, this->vec.x, this->vec.y, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::xxzx() const { return UVec4(this->vec.x, this->vec.x, this->vec.z, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::xxzy() const { return UVec4(this->vec.x, this->vec.x, this->vec.z, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::xxzz() const { return UVec4(this->vec.x, this->vec.x, this->vec.z, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::xxzw() const { return UVec4(this->vec.x, this->vec.x, this->vec.z, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::xxwx() const { return UVec4(this->vec.x, this->vec.x, this->vec.w, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::xxwy() const { return UVec4(this->vec.x, this->vec.x, this->vec.w, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::xxwz() const { return UVec4(this->vec.x, this->vec.x, this->vec.w, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::xxww() const { return UVec4(this->vec.x, this->vec.x, this->vec.w, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::xyxx() const { return UVec4(this->vec.x, this->vec.y, this->vec.x, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::xyxy() const { return UVec4(this->vec.x, this->vec.y, this->vec.x, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::xyxz() const { return UVec4(this->vec.x, this->vec.y, this->vec.x, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::xyxw() const { return UVec4(this->vec.x, this->vec.y, this->vec.x, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::xyyx() const { return UVec4(this->vec.x, this->vec.y, this->vec.y, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::xyyy() const { return UVec4(this->vec.x, this->vec.y, this->vec.y, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::xyyz() const { return UVec4(this->vec.x, this->vec.y, this->vec.y, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::xyyw() const { return UVec4(this->vec.x, this->vec.y, this->vec.y, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::xyzx() const { return UVec4(this->vec.x, this->vec.y, this->vec.z, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::xyzy() const { return UVec4(this->vec.x, this->vec.y, this->vec.z, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::xyzz() const { return UVec4(this->vec.x, this->vec.y, this->vec.z, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::xyzw() const { return UVec4(this->vec.x, this->vec.y, this->vec.z, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::xywx() const { return UVec4(this->vec.x, this->vec.y, this->vec.w, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::xywy() const { return UVec4(this->vec.x, this->vec.y, this->vec.w, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::xywz() const { return UVec4(this->vec.x, this->vec.y, this->vec.w, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::xyww() const { return UVec4(this->vec.x, this->vec.y, this->vec.w, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::xzxx() const { return UVec4(this->vec.x, this->vec.z, this->vec.x, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::xzxy() const { return UVec4(this->vec.x, this->vec.z, this->vec.x, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::xzxz() const { return UVec4(this->vec.x, this->vec.z, this->vec.x, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::xzxw() const { return UVec4(this->vec.x, this->vec.z, this->vec.x, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::xzyx() const { return UVec4(this->vec.x, this->vec.z, this->vec.y, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::xzyy() const { return UVec4(this->vec.x, this->vec.z, this->vec.y, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::xzyz() const { return UVec4(this->vec.x, this->vec.z, this->vec.y, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::xzyw() const { return UVec4(this->vec.x, this->vec.z, this->vec.y, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::xzzx() const { return UVec4(this->vec.x, this->vec.z, this->vec.z, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::xzzy() const { return UVec4(this->vec.x, this->vec.z, this->vec.z, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::xzzz() const { return UVec4(this->vec.x, this->vec.z, this->vec.z, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::xzzw() const { return UVec4(this->vec.x, this->vec.z, this->vec.z, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::xzwx() const { return UVec4(this->vec.x, this->vec.z, this->vec.w, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::xzwy() const { return UVec4(this->vec.x, this->vec.z, this->vec.w, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::xzwz() const { return UVec4(this->vec.x, this->vec.z, this->vec.w, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::xzww() const { return UVec4(this->vec.x, this->vec.z, this->vec.w, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::xwxx() const { return UVec4(this->vec.x, this->vec.w, this->vec.x, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::xwxy() const { return UVec4(this->vec.x, this->vec.w, this->vec.x, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::xwxz() const { return UVec4(this->vec.x, this->vec.w, this->vec.x, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::xwxw() const { return UVec4(this->vec.x, this->vec.w, this->vec.x, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::xwyx() const { return UVec4(this->vec.x, this->vec.w, this->vec.y, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::xwyy() const { return UVec4(this->vec.x, this->vec.w, this->vec.y, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::xwyz() const { return UVec4(this->vec.x, this->vec.w, this->vec.y, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::xwyw() const { return UVec4(this->vec.x, this->vec.w, this->vec.y, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::xwzx() const { return UVec4(this->vec.x, this->vec.w, this->vec.z, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::xwzy() const { return UVec4(this->vec.x, this->vec.w, this->vec.z, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::xwzz() const { return UVec4(this->vec.x, this->vec.w, this->vec.z, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::xwzw() const { return UVec4(this->vec.x, this->vec.w, this->vec.z, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::xwwx() const { return UVec4(this->vec.x, this->vec.w, this->vec.w, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::xwwy() const { return UVec4(this->vec.x, this->vec.w, this->vec.w, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::xwwz() const { return UVec4(this->vec.x, this->vec.w, this->vec.w, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::xwww() const { return UVec4(this->vec.x, this->vec.w, this->vec.w, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::yxxx() const { return UVec4(this->vec.y, this->vec.x, this->vec.x, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::yxxy() const { return UVec4(this->vec.y, this->vec.x, this->vec.x, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::yxxz() const { return UVec4(this->vec.y, this->vec.x, this->vec.x, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::yxxw() const { return UVec4(this->vec.y, this->vec.x, this->vec.x, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::yxyx() const { return UVec4(this->vec.y, this->vec.x, this->vec.y, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::yxyy() const { return UVec4(this->vec.y, this->vec.x, this->vec.y, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::yxyz() const { return UVec4(this->vec.y, this->vec.x, this->vec.y, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::yxyw() const { return UVec4(this->vec.y, this->vec.x, this->vec.y, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::yxzx() const { return UVec4(this->vec.y, this->vec.x, this->vec.z, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::yxzy() const { return UVec4(this->vec.y, this->vec.x, this->vec.z, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::yxzz() const { return UVec4(this->vec.y, this->vec.x, this->vec.z, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::yxzw() const { return UVec4(this->vec.y, this->vec.x, this->vec.z, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::yxwx() const { return UVec4(this->vec.y, this->vec.x, this->vec.w, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::yxwy() const { return UVec4(this->vec.y, this->vec.x, this->vec.w, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::yxwz() const { return UVec4(this->vec.y, this->vec.x, this->vec.w, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::yxww() const { return UVec4(this->vec.y, this->vec.x, this->vec.w, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::yyxx() const { return UVec4(this->vec.y, this->vec.y, this->vec.x, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::yyxy() const { return UVec4(this->vec.y, this->vec.y, this->vec.x, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::yyxz() const { return UVec4(this->vec.y, this->vec.y, this->vec.x, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::yyxw() const { return UVec4(this->vec.y, this->vec.y, this->vec.x, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::yyyx() const { return UVec4(this->vec.y, this->vec.y, this->vec.y, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::yyyy() const { return UVec4(this->vec.y, this->vec.y, this->vec.y, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::yyyz() const { return UVec4(this->vec.y, this->vec.y, this->vec.y, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::yyyw() const { return UVec4(this->vec.y, this->vec.y, this->vec.y, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::yyzx() const { return UVec4(this->vec.y, this->vec.y, this->vec.z, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::yyzy() const { return UVec4(this->vec.y, this->vec.y, this->vec.z, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::yyzz() const { return UVec4(this->vec.y, this->vec.y, this->vec.z, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::yyzw() const { return UVec4(this->vec.y, this->vec.y, this->vec.z, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::yywx() const { return UVec4(this->vec.y, this->vec.y, this->vec.w, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::yywy() const { return UVec4(this->vec.y, this->vec.y, this->vec.w, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::yywz() const { return UVec4(this->vec.y, this->vec.y, this->vec.w, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::yyww() const { return UVec4(this->vec.y, this->vec.y, this->vec.w, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::yzxx() const { return UVec4(this->vec.y, this->vec.z, this->vec.x, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::yzxy() const { return UVec4(this->vec.y, this->vec.z, this->vec.x, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::yzxz() const { return UVec4(this->vec.y, this->vec.z, this->vec.x, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::yzxw() const { return UVec4(this->vec.y, this->vec.z, this->vec.x, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::yzyx() const { return UVec4(this->vec.y, this->vec.z, this->vec.y, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::yzyy() const { return UVec4(this->vec.y, this->vec.z, this->vec.y, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::yzyz() const { return UVec4(this->vec.y, this->vec.z, this->vec.y, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::yzyw() const { return UVec4(this->vec.y, this->vec.z, this->vec.y, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::yzzx() const { return UVec4(this->vec.y, this->vec.z, this->vec.z, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::yzzy() const { return UVec4(this->vec.y, this->vec.z, this->vec.z, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::yzzz() const { return UVec4(this->vec.y, this->vec.z, this->vec.z, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::yzzw() const { return UVec4(this->vec.y, this->vec.z, this->vec.z, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::yzwx() const { return UVec4(this->vec.y, this->vec.z, this->vec.w, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::yzwy() const { return UVec4(this->vec.y, this->vec.z, this->vec.w, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::yzwz() const { return UVec4(this->vec.y, this->vec.z, this->vec.w, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::yzww() const { return UVec4(this->vec.y, this->vec.z, this->vec.w, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::ywxx() const { return UVec4(this->vec.y, this->vec.w, this->vec.x, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::ywxy() const { return UVec4(this->vec.y, this->vec.w, this->vec.x, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::ywxz() const { return UVec4(this->vec.y, this->vec.w, this->vec.x, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::ywxw() const { return UVec4(this->vec.y, this->vec.w, this->vec.x, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::ywyx() const { return UVec4(this->vec.y, this->vec.w, this->vec.y, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::ywyy() const { return UVec4(this->vec.y, this->vec.w, this->vec.y, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::ywyz() const { return UVec4(this->vec.y, this->vec.w, this->vec.y, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::ywyw() const { return UVec4(this->vec.y, this->vec.w, this->vec.y, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::ywzx() const { return UVec4(this->vec.y, this->vec.w, this->vec.z, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::ywzy() const { return UVec4(this->vec.y, this->vec.w, this->vec.z, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::ywzz() const { return UVec4(this->vec.y, this->vec.w, this->vec.z, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::ywzw() const { return UVec4(this->vec.y, this->vec.w, this->vec.z, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::ywwx() const { return UVec4(this->vec.y, this->vec.w, this->vec.w, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::ywwy() const { return UVec4(this->vec.y, this->vec.w, this->vec.w, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::ywwz() const { return UVec4(this->vec.y, this->vec.w, this->vec.w, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::ywww() const { return UVec4(this->vec.y, this->vec.w, this->vec.w, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::zxxx() const { return UVec4(this->vec.z, this->vec.x, this->vec.x, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::zxxy() const { return UVec4(this->vec.z, this->vec.x, this->vec.x, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::zxxz() const { return UVec4(this->vec.z, this->vec.x, this->vec.x, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::zxxw() const { return UVec4(this->vec.z, this->vec.x, this->vec.x, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::zxyx() const { return UVec4(this->vec.z, this->vec.x, this->vec.y, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::zxyy() const { return UVec4(this->vec.z, this->vec.x, this->vec.y, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::zxyz() const { return UVec4(this->vec.z, this->vec.x, this->vec.y, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::zxyw() const { return UVec4(this->vec.z, this->vec.x, this->vec.y, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::zxzx() const { return UVec4(this->vec.z, this->vec.x, this->vec.z, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::zxzy() const { return UVec4(this->vec.z, this->vec.x, this->vec.z, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::zxzz() const { return UVec4(this->vec.z, this->vec.x, this->vec.z, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::zxzw() const { return UVec4(this->vec.z, this->vec.x, this->vec.z, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::zxwx() const { return UVec4(this->vec.z, this->vec.x, this->vec.w, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::zxwy() const { return UVec4(this->vec.z, this->vec.x, this->vec.w, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::zxwz() const { return UVec4(this->vec.z, this->vec.x, this->vec.w, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::zxww() const { return UVec4(this->vec.z, this->vec.x, this->vec.w, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::zyxx() const { return UVec4(this->vec.z, this->vec.y, this->vec.x, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::zyxy() const { return UVec4(this->vec.z, this->vec.y, this->vec.x, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::zyxz() const { return UVec4(this->vec.z, this->vec.y, this->vec.x, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::zyxw() const { return UVec4(this->vec.z, this->vec.y, this->vec.x, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::zyyx() const { return UVec4(this->vec.z, this->vec.y, this->vec.y, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::zyyy() const { return UVec4(this->vec.z, this->vec.y, this->vec.y, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::zyyz() const { return UVec4(this->vec.z, this->vec.y, this->vec.y, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::zyyw() const { return UVec4(this->vec.z, this->vec.y, this->vec.y, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::zyzx() const { return UVec4(this->vec.z, this->vec.y, this->vec.z, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::zyzy() const { return UVec4(this->vec.z, this->vec.y, this->vec.z, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::zyzz() const { return UVec4(this->vec.z, this->vec.y, this->vec.z, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::zyzw() const { return UVec4(this->vec.z, this->vec.y, this->vec.z, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::zywx() const { return UVec4(this->vec.z, this->vec.y, this->vec.w, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::zywy() const { return UVec4(this->vec.z, this->vec.y, this->vec.w, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::zywz() const { return UVec4(this->vec.z, this->vec.y, this->vec.w, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::zyww() const { return UVec4(this->vec.z, this->vec.y, this->vec.w, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::zzxx() const { return UVec4(this->vec.z, this->vec.z, this->vec.x, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::zzxy() const { return UVec4(this->vec.z, this->vec.z, this->vec.x, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::zzxz() const { return UVec4(this->vec.z, this->vec.z, this->vec.x, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::zzxw() const { return UVec4(this->vec.z, this->vec.z, this->vec.x, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::zzyx() const { return UVec4(this->vec.z, this->vec.z, this->vec.y, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::zzyy() const { return UVec4(this->vec.z, this->vec.z, this->vec.y, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::zzyz() const { return UVec4(this->vec.z, this->vec.z, this->vec.y, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::zzyw() const { return UVec4(this->vec.z, this->vec.z, this->vec.y, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::zzzx() const { return UVec4(this->vec.z, this->vec.z, this->vec.z, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::zzzy() const { return UVec4(this->vec.z, this->vec.z, this->vec.z, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::zzzz() const { return UVec4(this->vec.z, this->vec.z, this->vec.z, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::zzzw() const { return UVec4(this->vec.z, this->vec.z, this->vec.z, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::zzwx() const { return UVec4(this->vec.z, this->vec.z, this->vec.w, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::zzwy() const { return UVec4(this->vec.z, this->vec.z, this->vec.w, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::zzwz() const { return UVec4(this->vec.z, this->vec.z, this->vec.w, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::zzww() const { return UVec4(this->vec.z, this->vec.z, this->vec.w, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::zwxx() const { return UVec4(this->vec.z, this->vec.w, this->vec.x, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::zwxy() const { return UVec4(this->vec.z, this->vec.w, this->vec.x, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::zwxz() const { return UVec4(this->vec.z, this->vec.w, this->vec.x, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::zwxw() const { return UVec4(this->vec.z, this->vec.w, this->vec.x, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::zwyx() const { return UVec4(this->vec.z, this->vec.w, this->vec.y, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::zwyy() const { return UVec4(this->vec.z, this->vec.w, this->vec.y, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::zwyz() const { return UVec4(this->vec.z, this->vec.w, this->vec.y, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::zwyw() const { return UVec4(this->vec.z, this->vec.w, this->vec.y, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::zwzx() const { return UVec4(this->vec.z, this->vec.w, this->vec.z, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::zwzy() const { return UVec4(this->vec.z, this->vec.w, this->vec.z, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::zwzz() const { return UVec4(this->vec.z, this->vec.w, this->vec.z, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::zwzw() const { return UVec4(this->vec.z, this->vec.w, this->vec.z, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::zwwx() const { return UVec4(this->vec.z, this->vec.w, this->vec.w, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::zwwy() const { return UVec4(this->vec.z, this->vec.w, this->vec.w, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::zwwz() const { return UVec4(this->vec.z, this->vec.w, this->vec.w, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::zwww() const { return UVec4(this->vec.z, this->vec.w, this->vec.w, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::wxxx() const { return UVec4(this->vec.w, this->vec.x, this->vec.x, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::wxxy() const { return UVec4(this->vec.w, this->vec.x, this->vec.x, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::wxxz() const { return UVec4(this->vec.w, this->vec.x, this->vec.x, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::wxxw() const { return UVec4(this->vec.w, this->vec.x, this->vec.x, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::wxyx() const { return UVec4(this->vec.w, this->vec.x, this->vec.y, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::wxyy() const { return UVec4(this->vec.w, this->vec.x, this->vec.y, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::wxyz() const { return UVec4(this->vec.w, this->vec.x, this->vec.y, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::wxyw() const { return UVec4(this->vec.w, this->vec.x, this->vec.y, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::wxzx() const { return UVec4(this->vec.w, this->vec.x, this->vec.z, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::wxzy() const { return UVec4(this->vec.w, this->vec.x, this->vec.z, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::wxzz() const { return UVec4(this->vec.w, this->vec.x, this->vec.z, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::wxzw() const { return UVec4(this->vec.w, this->vec.x, this->vec.z, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::wxwx() const { return UVec4(this->vec.w, this->vec.x, this->vec.w, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::wxwy() const { return UVec4(this->vec.w, this->vec.x, this->vec.w, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::wxwz() const { return UVec4(this->vec.w, this->vec.x, this->vec.w, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::wxww() const { return UVec4(this->vec.w, this->vec.x, this->vec.w, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::wyxx() const { return UVec4(this->vec.w, this->vec.y, this->vec.x, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::wyxy() const { return UVec4(this->vec.w, this->vec.y, this->vec.x, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::wyxz() const { return UVec4(this->vec.w, this->vec.y, this->vec.x, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::wyxw() const { return UVec4(this->vec.w, this->vec.y, this->vec.x, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::wyyx() const { return UVec4(this->vec.w, this->vec.y, this->vec.y, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::wyyy() const { return UVec4(this->vec.w, this->vec.y, this->vec.y, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::wyyz() const { return UVec4(this->vec.w, this->vec.y, this->vec.y, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::wyyw() const { return UVec4(this->vec.w, this->vec.y, this->vec.y, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::wyzx() const { return UVec4(this->vec.w, this->vec.y, this->vec.z, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::wyzy() const { return UVec4(this->vec.w, this->vec.y, this->vec.z, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::wyzz() const { return UVec4(this->vec.w, this->vec.y, this->vec.z, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::wyzw() const { return UVec4(this->vec.w, this->vec.y, this->vec.z, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::wywx() const { return UVec4(this->vec.w, this->vec.y, this->vec.w, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::wywy() const { return UVec4(this->vec.w, this->vec.y, this->vec.w, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::wywz() const { return UVec4(this->vec.w, this->vec.y, this->vec.w, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::wyww() const { return UVec4(this->vec.w, this->vec.y, this->vec.w, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::wzxx() const { return UVec4(this->vec.w, this->vec.z, this->vec.x, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::wzxy() const { return UVec4(this->vec.w, this->vec.z, this->vec.x, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::wzxz() const { return UVec4(this->vec.w, this->vec.z, this->vec.x, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::wzxw() const { return UVec4(this->vec.w, this->vec.z, this->vec.x, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::wzyx() const { return UVec4(this->vec.w, this->vec.z, this->vec.y, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::wzyy() const { return UVec4(this->vec.w, this->vec.z, this->vec.y, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::wzyz() const { return UVec4(this->vec.w, this->vec.z, this->vec.y, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::wzyw() const { return UVec4(this->vec.w, this->vec.z, this->vec.y, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::wzzx() const { return UVec4(this->vec.w, this->vec.z, this->vec.z, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::wzzy() const { return UVec4(this->vec.w, this->vec.z, this->vec.z, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::wzzz() const { return UVec4(this->vec.w, this->vec.z, this->vec.z, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::wzzw() const { return UVec4(this->vec.w, this->vec.z, this->vec.z, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::wzwx() const { return UVec4(this->vec.w, this->vec.z, this->vec.w, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::wzwy() const { return UVec4(this->vec.w, this->vec.z, this->vec.w, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::wzwz() const { return UVec4(this->vec.w, this->vec.z, this->vec.w, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::wzww() const { return UVec4(this->vec.w, this->vec.z, this->vec.w, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::wwxx() const { return UVec4(this->vec.w, this->vec.w, this->vec.x, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::wwxy() const { return UVec4(this->vec.w, this->vec.w, this->vec.x, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::wwxz() const { return UVec4(this->vec.w, this->vec.w, this->vec.x, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::wwxw() const { return UVec4(this->vec.w, this->vec.w, this->vec.x, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::wwyx() const { return UVec4(this->vec.w, this->vec.w, this->vec.y, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::wwyy() const { return UVec4(this->vec.w, this->vec.w, this->vec.y, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::wwyz() const { return UVec4(this->vec.w, this->vec.w, this->vec.y, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::wwyw() const { return UVec4(this->vec.w, this->vec.w, this->vec.y, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::wwzx() const { return UVec4(this->vec.w, this->vec.w, this->vec.z, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::wwzy() const { return UVec4(this->vec.w, this->vec.w, this->vec.z, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::wwzz() const { return UVec4(this->vec.w, this->vec.w, this->vec.z, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::wwzw() const { return UVec4(this->vec.w, this->vec.w, this->vec.z, this->vec.w); }
onyx::math::UVec4 onyx::math::UVec4::wwwx() const { return UVec4(this->vec.w, this->vec.w, this->vec.w, this->vec.x); }
onyx::math::UVec4 onyx::math::UVec4::wwwy() const { return UVec4(this->vec.w, this->vec.w, this->vec.w, this->vec.y); }
onyx::math::UVec4 onyx::math::UVec4::wwwz() const { return UVec4(this->vec.w, this->vec.w, this->vec.w, this->vec.z); }
onyx::math::UVec4 onyx::math::UVec4::wwww() const { return UVec4(this->vec.w, this->vec.w, this->vec.w, this->vec.w); }
