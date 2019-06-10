#!/bin/bash
(find . -type f && find . -type d) | wc -l | sed -E "s/[	 ]//g"

