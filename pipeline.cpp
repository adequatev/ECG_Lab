#include "pipeline.h"
#define M_PI 3.1415
//void Pipeline::InitScaleTransform(Matrix4f& m) const
//{
//    m.m[0][0] = m_scale.x; m.m[0][1] = 0.0f; m.m[0][2] = 0.0f; m.m[0][3] = 0.0f;
//    m.m[1][0] = 0.0f; m.m[1][1] = m_scale.y; m.m[1][2] = 0.0f; m.m[1][3] = 0.0f;
//    m.m[2][0] = 0.0f; m.m[2][1] = 0.0f; m.m[2][2] = m_scale.z; m.m[2][3] = 0.0f;
//    m.m[3][0] = 0.0f; m.m[3][1] = 0.0f; m.m[3][2] = 0.0f; m.m[3][3] = 1.0f;
//}
//
//void Pipeline::InitRotateTransform(Matrix4f& m) const
//{
//    Matrix4f rx, ry, rz;
//
//    const float x = ToRadian(m_rotateInfo.x);
//    const float y = ToRadian(m_rotateInfo.y);
//    const float z = ToRadian(m_rotateInfo.z);
//
//    rx.m[0][0] = 1.0f; rx.m[0][1] = 0.0f;       rx.m[0][2] = 0.0f;      rx.m[0][3] = 0.0f;
//    rx.m[1][0] = 0.0f; rx.m[1][1] = cosf(x);    rx.m[1][2] = -sinf(x);  rx.m[1][3] = 0.0f;
//    rx.m[2][0] = 0.0f; rx.m[2][1] = sinf(x);    rx.m[2][2] = cosf(x);   rx.m[2][3] = 0.0f;
//    rx.m[3][0] = 0.0f; rx.m[3][1] = 0.0f;       rx.m[3][2] = 0.0f;      rx.m[3][3] = 1.0f;
//
//    ry.m[0][0] = cosf(y);   ry.m[0][1] = 0.0f; ry.m[0][2] = -sinf(y);   ry.m[0][3] = 0.0f;
//    ry.m[1][0] = 0.0f;      ry.m[1][1] = 1.0f; ry.m[1][2] = 0.0f;       ry.m[1][3] = 0.0f;
//    ry.m[2][0] = sinf(y);   ry.m[2][1] = 0.0f; ry.m[2][2] = cosf(y);    ry.m[2][3] = 0.0f;
//    ry.m[3][0] = 0.0f;      ry.m[3][1] = 0.0f; ry.m[3][2] = 0.0f;       ry.m[3][3] = 1.0f;
//
//    rz.m[0][0] = cosf(z);   rz.m[0][1] = -sinf(z);  rz.m[0][2] = 0.0f;  rz.m[0][3] = 0.0f;
//    rz.m[1][0] = sinf(z);   rz.m[1][1] = cosf(z);   rz.m[1][2] = 0.0f;  rz.m[1][3] = 0.0f;
//    rz.m[2][0] = 0.0f;      rz.m[2][1] = 0.0f;      rz.m[2][2] = 1.0f;  rz.m[2][3] = 0.0f;
//    rz.m[3][0] = 0.0f;      rz.m[3][1] = 0.0f;      rz.m[3][2] = 0.0f;  rz.m[3][3] = 1.0f;
//
//    m = rz * ry * rx;
//}
//
//void Pipeline::InitTranslationTransform(Matrix4f& m) const
//{
//    m.m[0][0] = 1.0f; m.m[0][1] = 0.0f; m.m[0][2] = 0.0f; m.m[0][3] = m_worldPos.x;
//    m.m[1][0] = 0.0f; m.m[1][1] = 1.0f; m.m[1][2] = 0.0f; m.m[1][3] = m_worldPos.y;
//    m.m[2][0] = 0.0f; m.m[2][1] = 0.0f; m.m[2][2] = 1.0f; m.m[2][3] = m_worldPos.z;
//    m.m[3][0] = 0.0f; m.m[3][1] = 0.0f; m.m[3][2] = 0.0f; m.m[3][3] = 1.0f;
//}
//
//void Pipeline::InitPerspectiveProj(Matrix4f& m) const
//{
//    const float ar = m_persProj.Width / m_persProj.Height;
//    const float zNear = m_persProj.zNear;
//    const float zFar = m_persProj.zFar;
//    const float zRange = zNear - zFar;
//    const float tanHalfFOV = tanf(ToRadian(m_persProj.FOV / 2.0f));
//
//    m.m[0][0] = 1.0f / (tanHalfFOV * ar); m.m[0][1] = 0.0f;            m.m[0][2] = 0.0f;                   m.m[0][3] = 0.0;
//    m.m[1][0] = 0.0f;                   m.m[1][1] = 1.0f / tanHalfFOV; m.m[1][2] = 0.0f;                   m.m[1][3] = 0.0;
//    m.m[2][0] = 0.0f;                   m.m[2][1] = 0.0f;            m.m[2][2] = (-zNear - zFar) / zRange; m.m[2][3] = 2.0f * zFar * zNear / zRange;
//    m.m[3][0] = 0.0f;                   m.m[3][1] = 0.0f;            m.m[3][2] = 1.0f;                   m.m[3][3] = 0.0;
//}
const Matrix4f* Pipeline::GetTrans()
{
    Matrix4f ScaleTrans, RotateTrans, TranslationTrans, CameraTranslationTrans, CameraRotateTrans, PersProjTrans;

    ScaleTrans.InitScaleTransform(m_scale.x, m_scale.y, m_scale.z);
    RotateTrans.InitRotateTransform(m_rotateInfo.x, m_rotateInfo.y, m_rotateInfo.z);
    TranslationTrans.InitTranslationTransform(m_worldPos.x, m_worldPos.y, m_worldPos.z);
    CameraTranslationTrans.InitTranslationTransform(-m_camera.Pos.x, -m_camera.Pos.y, -m_camera.Pos.z);
    CameraRotateTrans.InitCameraTransform(m_camera.Target, m_camera.Up);
    PersProjTrans.InitPersProjTransform(m_persProj.FOV, m_persProj.Width, m_persProj.Height, m_persProj.zNear, m_persProj.zFar);

    m_transformation = PersProjTrans * CameraRotateTrans * CameraTranslationTrans * TranslationTrans * RotateTrans * ScaleTrans;
    return &m_transformation;
}

const Matrix4f& Pipeline::GetWorldTrans()
{
    Matrix4f ScaleTrans, RotateTrans, TranslationTrans;

    ScaleTrans.InitScaleTransform(m_scale.x, m_scale.y, m_scale.z);
    RotateTrans.InitRotateTransform(m_rotateInfo.x, m_rotateInfo.y, m_rotateInfo.z);
    TranslationTrans.InitTranslationTransform(m_worldPos.x, m_worldPos.y, m_worldPos.z);

    m_WorldTransformation = TranslationTrans * RotateTrans * ScaleTrans;
    return m_WorldTransformation;
}

const Matrix4f& Pipeline::GetWVPTrans()
{
    GetWorldTrans();

    Matrix4f CameraTranslationTrans, CameraRotateTrans, PersProjTrans;

    CameraTranslationTrans.InitTranslationTransform(-m_camera.Pos.x, -m_camera.Pos.y, -m_camera.Pos.z);
    CameraRotateTrans.InitCameraTransform(m_camera.Target, m_camera.Up);
    PersProjTrans.InitPersProjTransform(m_persProj.FOV, m_persProj.Width, m_persProj.Height, m_persProj.zNear, m_persProj.zFar);

    m_WVPtransformation = PersProjTrans * CameraRotateTrans * CameraTranslationTrans * m_WorldTransformation;
    return m_WVPtransformation;
}
