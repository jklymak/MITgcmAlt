C $Header: /u/gcmpack/MITgcm/pkg/exf/EXF_FIELDS.h,v 1.11 2010/04/14 23:02:18 gforget Exp $
C $Name:  $
c
c
C     ==================================================================
C     HEADER exf_fields
C     ==================================================================
c
C     o Header file for the surface flux data.
c
C     started: Ralf.Giering@FastOpt.de 25-Mai-2000
C     changed: field swap in adj. mode; heimbach@mit.edu 10-Jan-2002
C     included runoff D. Stammer, Nov. 25, 2001
C     mods for pkg/seaice: menemenlis@jpl.nasa.gov 20-Dec-2002
c
C     ==================================================================
C     HEADER exf_fields
C     ==================================================================
c
c
C     Field definitions, units, and sign conventions:
C     ===============================================
c
C     ustress   :: Zonal surface wind stress in N/m^2
C                  > 0 for increase in uVel, which is west to
C                      east for cartesian and spherical polar grids
C                  Typical range: -0.5 < ustress < 0.5
C                  Input field
c
C     vstress   :: Meridional surface wind stress in N/m^2
C                  > 0 for increase in vVel, which is south to
C                      north for cartesian and spherical polar grids
C                  Typical range: -0.5 < vstress < 0.5
C                  Input field
c
C     hflux     :: Net upward surface heat flux excluding shortwave in W/m^2
C                  hflux = latent + sensible + lwflux + swflux
C                  > 0 for decrease in theta (ocean cooling)
C                  Typical range: -250 < hflux < 600
C                  Input field
c
C     sflux     :: Net upward freshwater flux in m/s
C                  sflux = evap - precip - runoff
C                  > 0 for increase in salt (ocean salinity)
C                  Typical range: -1e-7 < sflux < 1e-7
C                  Input field
c
C     swflux    :: Net upward shortwave radiation in W/m^2
C                  swflux = - ( swdown - ice and snow absorption - reflected )
C                  > 0 for decrease in theta (ocean cooling)
C                  Typical range: -350 < swflux < 0
C                  Input field
c
C     uwind     :: Surface (10-m) zonal wind velocity in m/s
C                  > 0 for increase in uVel, which is west to
C                      east for cartesian and spherical polar grids
C                  Typical range: -10 < uwind < 10
C                  Input or input/output field
c
C     vwind     :: Surface (10-m) meridional wind velocity in m/s
C                  > 0 for increase in vVel, which is south to
C                      north for cartesian and spherical polar grids
C                  Typical range: -10 < vwind < 10
C                  Input or input/output field
c
C     wspeed    :: Surface (10-m) wind speed in m/s
C                  >= 0 sqrt(u^2+v^2)
C                  Typical range: 0 < wspeed < 10
C                  Input or input/output field
c
C     atemp     :: Surface (2-m) air temperature in deg K
C                  Typical range: 200 < atemp < 300
C                  Input or input/output field
c
C     aqh       :: Surface (2m) specific humidity in kg/kg
C                  Typical range: 0 < aqh < 0.02
C                  Input or input/output field
c
C     lwflux    :: Net upward longwave radiation in W/m^2
C                  lwflux = - ( lwdown - ice and snow absorption - emitted )
C                  > 0 for decrease in theta (ocean cooling)
C                  Typical range: -20 < lwflux < 170
C                  Input field
c
C     evap      :: Evaporation in m/s
C                  > 0 for increase in salt (ocean salinity)
C                  Typical range: 0 < evap < 2.5e-7
C                  Input, input/output, or output field
c
C     precip    :: Total Precipitation (rain+snow) in m/s of liquid water
C                  > 0 for decrease in salt (ocean salinity)
C                  Typical range: 0 < precip < 5e-7
C                  Input or input/output field
c
C     snowprecip :: snow precipitation in m/s of equivalent liquid water
C                  > 0 for decrease in salt (ocean salinity)
C                  Typical range: 0 < precip < 5e-7
C                  Input or input/output field
c
C     runoff    :: River and glacier runoff in m/s
C                  > 0 for decrease in salt (ocean salinity)
C                  Typical range: 0 < runoff < ????
C                  Input or input/output field
c
C     swdown    :: Downward shortwave radiation in W/m^2
C                  > 0 for increase in theta (ocean warming)
C                  Typical range: 0 < swdown < 450
C                  Input/output field
c
C     lwdown    :: Downward longwave radiation in W/m^2
C                  > 0 for increase in theta (ocean warming)
C                  Typical range: 50 < lwdown < 450
C                  Input/output field
c
C     apressure :: Atmospheric pressure field in N/m^2
C                  > 0 for ????
C                  Typical range: ???? < apressure < ????
C                  Input field
c
C     hs        :: sensible heat flux into ocean in W/m^2
C                  > 0 for increase in theta (ocean warming)
c
C     hl        :: latent   heat flux into ocean in W/m^2
C                  > 0 for increase in theta (ocean warming)
c
c
C     NOTES:
C     ======
c
C     By default all surface forcing fields are defined at the center
C     of each grid (the rVel location in model/inc/GRID.h) unless
C     flags readStressOnAgrid or readStressOnCgrid are set.
c
C     Input and output units and sign conventions can be customized
C     using variables exf_inscal_* and exf_outscal_*, which are set
C     by exf_readparms.F
c
C     Output fields fu, fv, Qnet, Qsw, and EmPmR are
C     defined in FFIELDS.h
c
C     Arrays *0 and *1 below are used for temporal interpolation.
c

      COMMON /exf_stress_r/ ustress, vstress
      _RL ustress   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL vstress   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      COMMON /exfl_ustress_r/ ustress0, ustress1
      _RL ustress0  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL ustress1  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      COMMON /exfl_vstress_r/ vstress0, vstress1
      _RL vstress0  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL vstress1  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)

      COMMON /exf_wspeed_r/ wspeed
      _RL wspeed   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      COMMON /exfl_wspeed_r/ wspeed0, wspeed1
      _RL wspeed0  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL wspeed1  (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)

      COMMON /exf_atm_wind_r/ uwind, vwind
      _RL uwind     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL vwind     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      COMMON /exfl_uwind_r/ uwind0, uwind1
      _RL uwind0    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL uwind1    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      COMMON /exfl_vwind_r/ vwind0, vwind1
      _RL vwind0    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL vwind1    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)

      COMMON /exf_hsflux_r/ hflux, sflux
      _RL hflux     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL sflux     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      COMMON /exfl_hflux_r/ hflux0, hflux1
      _RL hflux0    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL hflux1    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      COMMON /exfl_sflux_r/ sflux0, sflux1
      _RL sflux0    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL sflux1    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)

#ifdef ALLOW_ATM_TEMP
      COMMON /exf_atm_temp_r/ atemp, aqh, lwflux, precip, snowprecip
      _RL atemp     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL aqh       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL lwflux    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL precip    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL snowprecip (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      COMMON /exfl_atemp_r/ atemp0, atemp1
      _RL atemp0    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL atemp1    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      COMMON /exfl_aqh_r/ aqh0, aqh1
      _RL aqh0      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL aqh1      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      COMMON /exfl_lwflux_r/ lwflux0, lwflux1
      _RL lwflux0   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL lwflux1   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      COMMON /exfl_precip_r/ precip0, precip1
      _RL precip0   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL precip1   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      COMMON /exfl_snowprecip_r/ snowprecip0, snowprecip1
      _RL snowprecip0(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL snowprecip1(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      COMMON /exfl_turb_r/ hs, hl
      _RL hs        (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL hl        (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
#endif

C     wStress   :: wind-stress magnitude [Pa=N/m^2], @ grid-cell center
C     sh        :: wind-speed [m/s] (always larger than uMin)
      COMMON /exfl_wind_r/ wStress, cw, sw, sh
      _RL wStress   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL cw        (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL sw        (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL sh        (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)

#if defined(ALLOW_ATM_TEMP) || defined(SHORTWAVE_HEATING)
      COMMON /exf_swflux_r/ swflux
      _RL swflux    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      COMMON /exfl_swflux_r/ swflux0, swflux1
      _RL swflux0   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL swflux1   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
#endif

#if defined(ALLOW_ATM_TEMP) || defined(EXF_READ_EVAP)
      COMMON /exf_evap/ evap
      _RL evap      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      COMMON /exfl_evap_r/ evap0, evap1
      _RL evap0     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL evap1     (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
#endif

#ifdef ALLOW_DOWNWARD_RADIATION
      COMMON /exf_rad_down_r/
     &     swdown, lwdown, swdown0, swdown1, lwdown0, lwdown1
      _RL swdown    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL lwdown    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL swdown0   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL swdown1   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL lwdown0   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL lwdown1   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
#ifdef ALLOW_ZENITHANGLE
C---  COMMON /exf_zenith_angle_r/
C     zen_albedo_table   :: reference table of daily mean albedo
C     zen_albedo_pointer :: location of grid point in zen_albedo_table
C     zen_albedo         :: overall albedo (direct=f(zen) + diffus=cst)
C     zen_fsol_diurnal   :: incoming solar radiation (daily variable)
C     zen_fsol_daily     :: incoming solar radiation (daily mean)
      COMMON /exf_zenith_angle_r/ 
     &     zen_albedo_table, zen_albedo_pointer,
     &     zen_albedo, zen_fsol_diurnal, zen_fsol_daily
      _RL zen_albedo_table (366,181)
      _RL zen_albedo_pointer (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL zen_albedo (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL zen_fsol_diurnal (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL zen_fsol_daily (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
#endif
#endif

#ifdef ATMOSPHERIC_LOADING
      COMMON /exf_apressure_r/ apressure, apressure0, apressure1
      _RL apressure (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL apressure0(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL apressure1(1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
#endif

#ifdef ALLOW_RUNOFF
      COMMON /exfl_runoff_r/ runoff, runoff0, runoff1
      _RL runoff    (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL runoff0   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL runoff1   (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
#endif

#ifdef ALLOW_ICE_AREAMASK
      COMMON /exf_ice_areamask_r/ areamask,
     &                        areamask0, areamask1
      _RL areamask       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL areamask0      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL areamask1      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
#endif

#ifdef ALLOW_CLIMSST_RELAXATION
      COMMON /exf_clim_sst_r/ climsst,
     &                        climsst0, climsst1
      _RL climsst       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL climsst0      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL climsst1      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
#endif

#ifdef ALLOW_CLIMSSS_RELAXATION
      COMMON /exf_clim_sss_r/ climsss,
     &                        climsss0, climsss1
      _RL climsss       (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL climsss0      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
      _RL climsss1      (1-OLx:sNx+OLx,1-OLy:sNy+OLy,nSx,nSy)
#endif

