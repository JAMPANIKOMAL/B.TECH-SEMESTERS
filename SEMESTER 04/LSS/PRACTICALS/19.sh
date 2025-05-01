#!/bin/bash

failed_login_count()
{
    grep "Failed password" /var/log/auth.log | wc -l
}

failed_login_count
