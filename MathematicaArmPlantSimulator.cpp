#include "WolframLibrary.h"
//#include "ArmPlantSimulator.h"
#include <vector>

extern "C"
{
    // wrapper to C++ class
    //ArmPlantSimulator* engine;
    
    /* Return the version of Library Link */
    DLLEXPORT mint WolframLibrary_getVersion() {
        return WolframLibraryVersion;
    }

    /* Initialize Library */
    DLLEXPORT int WolframLibrary_initialize(WolframLibraryData libData) {
        //libData->Message("MathematicaArmPlantSimulator: initialize\n");
        return LIBRARY_NO_ERROR;
    }

    /* Uninitialize Library */
    DLLEXPORT void WolframLibrary_uninitialize(WolframLibraryData libData) {
        //libData->Message("MathematicaArmPlantSimulator: uninitialized\n");
        return;
    }

    /**
    * Setup armsimulator
    *
    * arg[0]:   model path          [string]
    * arg[1]:   index body          [string]
    * arg[2:4]: body offset         [3 x real]
    * arg[5]:   use muscles         [bool]
    * arg[6]:   use dual channel    [bool]
    * arg[7]:   initial state       [string]
    * arg[8]:   use elbow const     [bool]
    * arg[9]:   use z-dir only      [bool]
    */
    DLLEXPORT int setup(WolframLibraryData libData, mint Argc, MArgument *Args,
        MArgument Res) {
        // read input
        char* modelPath = MArgument_getUTF8String(Args[0]);
        char* body = MArgument_getUTF8String(Args[1]);
        mreal indexX = MArgument_getReal(Args[2]);
        mreal indexY = MArgument_getReal(Args[3]);
        mreal indexZ = MArgument_getReal(Args[4]);
        mbool useMuscles = MArgument_getBoolean(Args[5]);
        mbool useDualChannel = MArgument_getBoolean(Args[6]);
        char* initialState = MArgument_getUTF8String(Args[7]);
        mbool useElbowConstraint = MArgument_getBoolean(Args[8]);
        mbool useZDirOnly = MArgument_getBoolean(Args[9]);

        // construct arm simulator
        /*engine = new ArmPlantSimulator(modelPath, body,
            indexX, indexY, indexZ, useMuscles, useDualChannel, initialState,
            useElbowConstraint, useZDirOnly);*/

        return LIBRARY_NO_ERROR;
    }

    /**
    * Setup step
    *
    * arg[0]:   target time         [real]
    * arg[1:3]: channel1 acc        [3 x real]
    * arg[4:6]: channel2 acc        [3 x real]
    */
    DLLEXPORT int step(WolframLibraryData libData, mint Argc, MArgument *Args,
        MArgument Res) {
        try {
            /* engine->step(
                 MArgument_getReal(Args[0]),

                 MArgument_getReal(Args[1]),
                 MArgument_getReal(Args[2]),
                 MArgument_getReal(Args[3]),

                 MArgument_getReal(Args[4]),
                 MArgument_getReal(Args[5]),
                 MArgument_getReal(Args[6]));*/
        } catch (const std::exception& ex) {
            libData->Message(ex.what());
            return LIBRARY_FUNCTION_ERROR;
        } catch (...) {
            libData->Message("Unrecognized exception in function: step");
            return LIBRARY_FUNCTION_ERROR;
        }

        return LIBRARY_NO_ERROR;
    }

    DLLEXPORT int getPosition(WolframLibraryData libData, mint Argc,
        MArgument *Args, MArgument Res) {
        int err = LIBRARY_NO_ERROR;

        // read pos from armsimulator
        /*
        auto pos = engine->getEndEffectorPosition()
        */

        // pass results to Mathematica vector
        MTensor result;
        mint dims[1];
        dims[0] = 3;
        err = libData->MTensor_new(MType_Real, 1, dims, &result);
        for (mint i = 1; i <= dims[0] && !err; i++) {
            err = libData->MTensor_setReal(result, &i, i * 2.0);
        }
        MArgument_setMTensor(Res, result);

        return err;
    }

    DLLEXPORT int getVelocity(WolframLibraryData libData, mint Argc,
        MArgument *Args, MArgument Res) {
        int err = LIBRARY_NO_ERROR;

        // read vel from armsimulator
        /*
        auto vel = engine->getEndEffectorVelocity()
        */

        // pass results to Mathematica vector
        MTensor result;
        mint dims[1];
        dims[0] = 3;
        err = libData->MTensor_new(MType_Real, 1, dims, &result);
        for (mint i = 1; i <= dims[0] && !err; i++) {
            err = libData->MTensor_setReal(result, &i, i * 2.0);
        }
        MArgument_setMTensor(Res, result);

        return err;
    }

    DLLEXPORT int getAcceleration(WolframLibraryData libData, mint Argc,
        MArgument *Args, MArgument Res) {
        int err = LIBRARY_NO_ERROR;

        // read acc from armsimulator
        /*
        auto acc = engine->getEndEffectorAcceleration()
        */

        // pass results to Mathematica vector
        MTensor result;
        mint dims[1];
        dims[0] = 3;
        err = libData->MTensor_new(MType_Real, 1, dims, &result);
        for (mint i = 1; i <= dims[0] && !err; i++) {
            err = libData->MTensor_setReal(result, &i, i * 2.0);
        }
        MArgument_setMTensor(Res, result);

        return err;
    }

    /**
    * Print simulation results
    *
    * arg[0]:   directory           [string]
    */
    DLLEXPORT int printResults(WolframLibraryData libData, mint Argc,
        MArgument *Args, MArgument Res) {
        char* dir = MArgument_getUTF8String(Args[0]);
        //engine->printResults(dir);
        return LIBRARY_NO_ERROR;
    }
}