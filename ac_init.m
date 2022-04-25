aileron = fixedWingSurface('aileron','on','Asymmetric',[-20,20]);
elevator = fixedWingSurface('elevator','on','Symmetric',[-20,20]);
rudder = fixedWingSurface('rudder','on','Symmetric',[-20,20]);

propellerL = fixedWingThrust('propellerL','on','Symmetric',[0,1]);
propellerR = fixedWingThrust('propellerR','on','Symmetric',[0,1]);

aircraft = fixedWingAircraft('aircraft',S_ref,b/2,c_mean);
aircraft.AngleSystem = "Degrees";
%% coeffs

aircraft = setCoefficient(aircraft, "CL", "Zero", CL_0);
aircraft = setCoefficient(aircraft, "CD", "Zero", CD_0);
aircraft = setCoefficient(aircraft, "CD", "Alpha", CD_a);
aircraft = setCoefficient(aircraft, "Cm", "Zero", Cm_0);
aircraft = setCoefficient(aircraft,"CL", "Alpha", CL_a);
aircraft = setCoefficient(aircraft,"Cm", "Alpha", Cm_a);
aircraft = setCoefficient(aircraft,"Cm", "Q", Cm_q);
aircraft = setCoefficient(aircraft,"Cl", "P", Cl_p);
aircraft = setCoefficient(aircraft,"Cn", "R", Cn_r);
aircraft = setCoefficient(aircraft,"Cn", "Beta", Cn_beta);

aircraft.Surfaces = [aileron, elevator, rudder];
aircraft.Thrusts = [propellerR,propellerL];

%% states
state = fixedWingState(aircraft);
state.AngleSystem="Degrees";
state.Mass = mass;
state.U = V_c;
state.Inertia.X = [0.00666; 0; 0];
state.Inertia.Y = [0; 0.00474; 0];
state.Inertia.Z = [0; 0; -0.00262];
state.XD=-10;