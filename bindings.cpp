#include "System.h"
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(orbslam2, m) {
  py::class_<ORB_SLAM2::System> system(m, "System");

  system.def(py::init<const std::string &, const std::string &,
                      ORB_SLAM2::System::eSensor, const bool>());

  system.def("TrackRGBD", &ORB_SLAM2::System::TrackRGBD_Eigen);
  system.def("GetTrajectory", &ORB_SLAM2::System::GetTrajectory);
  system.def("GetNumTrackedMapPoints", &ORB_SLAM2::System::GetNumTrackedMapPoints);
  system.def("GetNumTrackedKeyPoints", &ORB_SLAM2::System::GetNumTrackedKeyPoints);
  system.def("Reset", &ORB_SLAM2::System::Reset);

  py::enum_<ORB_SLAM2::System::eSensor>(system, "SensorType")
      .value("MONOCULAR", ORB_SLAM2::System::eSensor::MONOCULAR)
      .value("STEREO", ORB_SLAM2::System::eSensor::STEREO)
      .value("RGBD", ORB_SLAM2::System::eSensor::RGBD)
      .export_values();
}
