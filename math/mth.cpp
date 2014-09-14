/* Gravity newton box project.
 * Authors: tis-p30, kbsx32;
 * File purpose: Math functions implementation file.
 */

#include "mth.h"

/*
 *  Vector functions implementation
 */

// vector default constructor
mth::Vec::Vec(TypeUse NewX, TypeUse NewY, TypeUse NewZ) :
  X(NewX), Y(NewY), Z(NewZ)
{
}

// Default constructor by one number
mth::Vec::Vec(TypeUse NewCoord) :
  X(NewCoord), Y(NewCoord), Z(NewCoord)
{
}

// Vector copying constructor
mth::Vec::Vec(const Vec &SrcVec) :
  X(SrcVec.X), Y(SrcVec.Y), Z(SrcVec.Z)
{
}

// Getting vector coords function
TypeUse mth::Vec::operator[](int Ind) const
{
  return *(&X + Ind);
}

// Getting vector coords function reference
TypeUse &mth::Vec::operator[](int Ind)
{
  return *(&X + Ind);
}

// Vec + Vec function
mth::Vec mth::Vec::operator+ (const Vec &Vec1) const
{
  return Vec(X + Vec1[0], Y + Vec1[1], Z + Vec1[2]);
}

// Vec += Vec function
mth::Vec &mth::Vec::operator+=(const mth::Vec &Vec1)
{
  X += Vec1[0];
  Y += Vec1[1];
  Z += Vec1[2];
  return *this;
}

// Vec - Vec function
mth::Vec mth::Vec::operator- (const Vec &Vec1) const
{
  return Vec(X - Vec1[0], Y - Vec1[1], Z - Vec1[2]);
}

// Vec * Num function
mth::Vec mth::Vec::operator* (const TypeUse &Num) const
{
  return Vec(X * Num, Y * Num, Z * Num);
}

// Vector mult of Vecs function
mth::Vec mth::Vec::operator% (const Vec &Vec1) const
{
  return Vec(Y * Vec1[2] - Y * Vec1[1],
             Z * Vec1[0] - X * Vec1[2],
             X * Vec1[1] - Y * Vec1[0]);
}

// Getting vector length
TypeUse mth::Vec::Length() const
{
  TypeUse Len = X * X + Y * Y + Z * Z;
  if (Len != 0 && Len != 1)
    return sqrt(Len);
  return Len;
}

// Normilize current vector
mth::Vec &mth::Vec::SetNormalize()
{
  TypeUse LenSqr = X * X + Y * Y + Z * Z;
  if (LenSqr != 0 && LenSqr != 1)
  {
    TypeUse Len = sqrt(LenSqr);
    X = X / Len;
    Y = Y / Len;
    Z = Z / Len;
  }
  return *this;
}

// Get normalized vector
mth::Vec mth::Vec::GetNormalized() const
{
  TypeUse LenSqr = X * X + Y * Y + Z * Z;
  if (LenSqr != 0 && LenSqr != 1)
  {
    TypeUse Len = sqrt(LenSqr);
    return mth::Vec(X / Len, Y / Len, Z / Len);
  }

  return mth::Vec(X, Y, Z);
}

// Vector rotate By axis-X function
mth::Vec mth::Vec::RotateByX(const TypeUse AngX) const
{
  TypeUse cosa = cos(AngX), sina = sin(AngX);

  return Vec(X,
             Y * cosa - Z * sina,
             Y * sina + Z * cosa);
}

// Vector rotate By axis-Y function
mth::Vec mth::Vec::RotateByY(const TypeUse AngX) const
{
  TypeUse cosa = cos(AngX), sina = sin(AngX);

  return Vec(X * cosa + Z * sina,
             Y,
             Z * cosa - X * sina);
}

// Vector rotate By axis-Z function
mth::Vec mth::Vec::RotateByZ(const TypeUse AngX) const
{
  TypeUse cosa = cos(AngX), sina = sin(AngX);

  return Vec(X * cosa - Y * sina,
             X * sina + Y * cosa,
             Z);
}
