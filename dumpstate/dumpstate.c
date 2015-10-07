/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <dumpstate.h>

void dumpstate_board()
{
    dump_file("INTERRUPTS", "/proc/interrupts");
    dump_file("Power Management Stats", "/proc/msm_pm_stats");
    run_command("MODEM TOMBSTONES", 5, SU_PATH, "root", "ls", "-l", "/data/tombstones/mdm", NULL);
    dump_file("HSIC Control Events", "/sys/kernel/debug/ehci_hsic_msm_dbg/show_ctrl_events");
    dump_file("HSIC Data Events", "/sys/kernel/debug/ehci_hsic_msm_dbg/show_data_events");
    dump_file("RPM Master Stats", "/d/rpm_master_stats");
    dump_file("RPM stats", "/d/rpm_stats");
    run_command("RPM log", 5, SU_PATH, "root", "/system/bin/sh", "-c", "head -1024 /d/rpm_log", NULL);
};
