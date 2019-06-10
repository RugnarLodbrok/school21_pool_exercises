#!/bin/bash
echo $(groups $FT_USER) | tr ' ' ,
