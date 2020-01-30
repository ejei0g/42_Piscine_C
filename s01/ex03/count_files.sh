#!/usr/bin/env bash
find . | wc -l | awk '{print $1}'
